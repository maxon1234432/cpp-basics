#include <iostream>
#include <string>

using namespace std;

struct Marsh
{
    string starting_point;
    string final_destination;
    int route_number;
};

bool IsNumber(string number);
void AddMarshes(Marsh* marshes, const int kNumMarshes);
void SortMarshes(Marsh* marshes, const int kNumMarshes);
void PrintMarshes(Marsh* marshes, const int kNumMarshes);
void PrintRequiredMarsh(Marsh* marshes, const int kNumMarshes, int route_number);

int main()
{
    const int kNumMarshes = 8;
    Marsh marshes[kNumMarshes];
    AddMarshes(marshes, kNumMarshes);
    cout << string(80, '-') << endl;

    cout << "\nMarshes sorted by route number:\n";
    SortMarshes(marshes, kNumMarshes);
    PrintMarshes(marshes, kNumMarshes);
    cout << endl << string(80, '-') << endl;

    int route_number;
    cout << "\nEnter route number: ";
    cin >> route_number;
    PrintRequiredMarsh(marshes, kNumMarshes, route_number);

    return 0;
}

bool IsNumber(string number)
{
    for (size_t i = 0; i < number.length(); i++)
        if (!isdigit(number[i]))
            return 0;
    return 1;
}

void AddMarshes(Marsh* marshes, const int kNumMarshes)
{
    string buf;
    for (int i = 0; i < kNumMarshes; i++)
    {
        cout << "Marsh #" << i + 1 << "\nStarting point: ";
        getline(cin, marshes[i].starting_point);

        cout << "Final destination: ";
        getline(cin, marshes[i].final_destination);

    repeat_route_number:
        cout << "Route number: ";
        getline(cin, buf);
        if (!IsNumber(buf))
        {
            cout << "Error: digits only!\n";
            goto repeat_route_number;
        }
        marshes[i].route_number = stoi(buf);
        cout << endl;
    }
}

void SortMarshes(Marsh* marshes, const int kNumMarshes)
{
    for (int i = 0; i < kNumMarshes - 1; i++)
        for (int j = 0; j < kNumMarshes - i - 1; j++)
            if (marshes[j].route_number > marshes[j + 1].route_number)
                swap(marshes[j], marshes[j + 1]);
}

void PrintMarshes(Marsh* marshes, const int kNumMarshes)
{
    for (int i = 0; i < kNumMarshes; i++)
    {
        cout << "\nStarting point: " << marshes[i].starting_point;
        cout << "\nFinal destination: " << marshes[i].final_destination;
        cout << "\nRoute number: " << marshes[i].route_number << endl;
    }
}

void PrintRequiredMarsh(Marsh* marshes, const int kNumMarshes, int route_number)
{
    bool marsh_found = false;
    for (int i = 0; i < kNumMarshes; i++)
    {
        if (marshes[i].route_number == route_number)
        {
            cout << "\nStarting point: " << marshes[i].starting_point;
            cout << "\nFinal destination: " << marshes[i].final_destination;
            cout << endl;
            marsh_found = true;
        }
    }

    if (!marsh_found)
        cout << "Marsh not found.\n";
}