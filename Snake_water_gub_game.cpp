
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

char get_computer_choice()
{
    int random = rand() % 3;
    if (random == 0)
        return 's';
    if (random == 1)
        return 'w';
    return 'g';
}

string get_choice_name(char c)
{
    if (c == 's')
        return "Snake";
    if (c == 'w')
        return "Water";
    if (c == 'g')
        return "Gun";
    return "Unknown";
}

string get_result(char user, char computer)
{
    if (user == computer)
        return "It's a tie!";
    if ((user == 's' && computer == 'w') ||
        (user == 'w' && computer == 'g') ||
        (user == 'g' && computer == 's'))
        return "You win!";
    return "Computer wins!";
}

void print_rules()
{
    cout << "\n===== Snake Water Gun Game =====\n";
    cout << "Rules:\n";
    cout << "Snake drinks water\n";
    cout << "Water drowns gun\n";
    cout << "Gun shoots snake\n";
    cout << "Enter 's' for Snake, 'w' for Water, 'g' for Gun.\n";
    cout << "Type 'q' to quit the game.\n\n";
}

int main()
{
    srand(time(0));
    int user_score = 0, computer_score = 0, rounds = 0;
    char choice;
    print_rules();
    while (true)
    {
        cout << "\nRound " << (rounds + 1) << ": Enter your choice (s/w/g or q to quit): ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'q')
        {
            cout << "\nThanks for playing!\n";
            break;
        }
        if (choice != 's' && choice != 'w' && choice != 'g')
        {
            cout << "Invalid input. Please enter 's', 'w', 'g', or 'q'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        char computer_choice = get_computer_choice();
        cout << "You chose: " << get_choice_name(choice) << endl;
        cout << "Computer chose: " << get_choice_name(computer_choice) << endl;
        string result = get_result(choice, computer_choice);
        cout << result << endl;
        if (result == "You win!")
            user_score++;
        else if (result == "Computer wins!")
            computer_score++;
        rounds++;
        cout << "Score => You: " << user_score << " | Computer: " << computer_score << endl;
    }
    cout << "\nFinal Score after " << rounds << " rounds:" << endl;
    cout << "You: " << user_score << " | Computer: " << computer_score << endl;
    if (user_score > computer_score)
        cout << "Congratulations! You are the overall winner!\n";
    else if (user_score < computer_score)
        cout << "Computer wins overall. Better luck next time!\n";
    else
        cout << "It's an overall tie!\n";
    return 0;
}