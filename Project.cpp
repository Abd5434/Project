#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int num = 20;
const int clubPlayers = 25;
const int clubCoaches = 3;
const int achievements = 5;
const int scheduleNumber = 10;

int usersCount = 0;
string userArrName[num];
string userArrPassword[num];
string userArrRole[num];
string clubPlayersName[clubPlayers];
int clubPlayersAge[clubPlayers];
string clubPlayersRole[clubPlayers];
string clubPlayersBattingStyle[clubPlayers];
string clubPlayersBowlingStyle[clubPlayers];
int clubPlayersSalary[clubPlayers];
string clubCoachesName[clubCoaches];
int clubCoachesAge[clubCoaches];
string clubCoachesRole[clubCoaches];
int clubCoachesSalary[clubCoaches];
string showAchievements[achievements];
string oppositions[scheduleNumber];
string dates[scheduleNumber];
string times[scheduleNumber];
string grounds[scheduleNumber];
int clubPlayerInnings[clubPlayers];
int clubPlayerRuns[clubPlayers];
int clubPlayerWickets[clubPlayers];
int clubPlayerHighScore[clubPlayers];
float clubPlayerAverage[clubPlayers];
string trainingDate[scheduleNumber];
string trainingTime[scheduleNumber];

string clubName = "Diamond Cricket Club";
int newTicketPrices = 200;
int currentPlayers = 0;
int currentCoaches = 0;

void header();
string login();
void subMenu(string subMenu);
string adminMenu();
string playerMenu();
string coachMenu();
string fanMenu();
string signIn(string name, string password);
bool signUp(string name, string password, string role);
void adminInterface();
void playerInterface();
void coachInterface();
void fanInterface();
void addPlayer();
void removePlayer();
void searchPlayer();
void checkFinances();
void addCoach();
void removeCoach();
void addAchievements();
void setTicketPrices();
void checkTeam();
void checkMgmtStaff();
void changePlayerName();
void scheduleMatch();
void checkSchedule();
void changePlayingX1();
void addPlayerPerformance();
void checkStats();
void scheduleTraining();
void checkAchievements();
void checkPlayingXI();
void checkTrainingSchedule();
void loadData();
void storeStatistics(string name , string role, int innings, int runs, int highScore, int average, int wickets);
void loadStatistics();
string parseWord(string line, int field);
void storeCricketersData(string name, string role, string battingStyle, string bowlingStyle, int age, int salary);
void loadCricketersData();
void storeCoachesData(string name, string role, int age, int salary);
void loadCoachesData();
void storeAchievements(string achievement1, string achievement2, string achievement3, string achievement4, string achievement5);
void loadAchievements();
void storeSchedule(string opposition, string date, string time, string ground);
void loadSchedule();
void storeTrainingSchedule(string date, string time);
void loadTrainingSchedule();
void storeData(string username, string password, string role);
void addUser(string username, string password, string role);
bool isValid(string username, string role);

main()
{
    loadData();
    loadCoachesData();
    loadCricketersData();
    //loadStatistics();
    loadAchievements();
    loadSchedule();
    loadTrainingSchedule();

    string option = "0";
    while (option != "3")
    {
        header();
        subMenu("Login");
        option = login();

        if (option == "1")
        {
            system("cls");
            header();
            subMenu("Signin");
            string name;
            string password;
            string role;

            cout << "Name: ";
            getline(cin,name);
            cout << "Password: ";
            getline(cin,password);

            role = signIn(name, password);

            if (role == "Admin")
            {
                system("cls");
                adminInterface();
            }

            else if (role == "Player")
            {
                system("cls");
                playerInterface();
            }

            else if (role == "Coach")
            {
                system("cls");
                coachInterface();
            }

            else if (role == "Fans")
            {
                system("cls");
                fanInterface();
            }
            else if (role == "nothing")
            {
                cout << "You have entered invalid credentials..." << endl;
                string anykey;
                cout << "Enter any key to continue...";
                getline(cin,anykey);
            }
        }

        else if (option == "2")
        {
            bool decision;
            system("cls");
            string name, password, role;
            header();
            subMenu("Sign up");
            cout << "Username: ";
            getline(cin,name);
            cout << "Password: ";
            getline(cin,password);
            cout << "Role (Admin / Coach / Player / Fans): ";
            getline(cin,role);;
            decision = isValid(name,role);
            if (decision == true)
            {
            bool ok = signUp(name, password, role);
            if (ok == true)
            {
                storeData(name, password,role);
                addUser(name,password,role);
                cout << "Signed up successfully." << endl;
            }

            else if (ok == false)
            {
                cout << "User capacity have been filled." << endl;
            }
            }
            else if(decision == false)
            {
                cout << "User already exists" << endl; 
            }
            cout << "Enter any key to continue...";
            string userEnter;
            getline(cin,userEnter);
        }
    }
}

void header()
{
    system("cls");
    cout << "*********************************************************************************************************************" << endl;
    cout << "*******************************************Cricket Club Management System********************************************" << endl;
    cout << "*********************************************************************************************************************" << endl;
    cout << endl
         << endl;
}

string login()
{
    cout << "1. Sign in" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    string option;
    cout << "Enter an option...";
    getline(cin,option);
    return option;
}

void subMenu(string subMenu)
{
    string message = subMenu + " Menu";
    cout << message << endl;
    cout << "-------------------" << endl;
}

string adminMenu()
{
    cout << "1. Add a player." << endl;
    cout << "2. Remove a player." << endl;
    cout << "3. Check Finances." << endl;
    cout << "4. Search a player." << endl;
    cout << "5. Add a coach." << endl;
    cout << "6. Remove a coach." << endl;
    cout << "7. Add Achievements." << endl;
    cout << "8. Set Ticket Prices." << endl;
    cout << "9. Check Team." << endl;
    cout << "10. Check Management Staff." << endl;
    cout << "11. Change a player's name." << endl;
    cout << "12. Schedule a match." << endl;
    cout << "13. Exit." << endl;
    cout << "Enter an option...";
    string option;
    getline(cin,option);
    return option;
}

string playerMenu()
{
    cout << "1. Check Schedule." << endl;
    cout << "2. Check Playing XI." << endl;
    cout << "3. Check Statistics." << endl;
    cout << "4. Check Achievements." << endl;
    cout << "5. Check Training Schedule." << endl;
    cout << "6. Exit." << endl;
    string option;
    cout << "Enter an option...";
    getline(cin,option);
    return option;
}

string coachMenu()
{
    cout << "1. Add a player." << endl;
    cout << "2. Remove a player." << endl;
    cout << "3. Search a player." << endl;
    cout << "4. Check Schedule." << endl;
    cout << "5. Check Team." << endl;
    cout << "6. Change playing XI." << endl;
    cout << "7. Check statistics of players." << endl;
    cout << "8. Schedule Training Session." << endl;
    cout << "9. Check Achievements." << endl;
    cout << "10. Add Player Statistics." << endl;
    cout << "11. Exit." << endl;
    string option;
    cout << "Enter your option...";
    getline(cin,option);
    return option;
}

string fanMenu()
{
    cout << "1. Check Schedule." << endl;
    cout << "2. Check Statistics of players" << endl;
    cout << "3. Check Achievements" << endl;
    cout << "4. Exit" << endl;
    string option;
    cout << "Enter your option...";
    getline(cin,option);
    return option;
}

string signIn(string name, string password)
{
    for (int idx = 0; idx < num; idx++)
    {
        if ((name == userArrName[idx]) && (password == userArrPassword[idx]))
        {
            return userArrRole[idx];
        }
    }
    return "nothing";
}

bool signUp(string name, string password, string role)
{
    if (usersCount < num)
    {
        userArrName[usersCount] = name;
        userArrPassword[usersCount] = password;
        userArrRole[usersCount] = role;
        usersCount++;
        return true;
    }

    else
    {
        return false;
    }
}

void adminInterface()
{
    string adminOption = "0";
    while (adminOption != "13")
    {
        system("cls");
        header();
        adminOption = adminMenu();
        system("cls");
        if (adminOption == "1")
        {
            header();
            addPlayer();
        }
        else if (adminOption == "2")
        {
            header();
            removePlayer();
        }
        else if (adminOption == "3")
        {
            header();
            checkFinances();
        }
        else if (adminOption == "4")
        {
            header();
            searchPlayer();
        }
        else if (adminOption == "5")
        {
            header();
            addCoach();
        }
        else if (adminOption == "6")
        {
            header();
            removeCoach();
        }
        else if (adminOption == "7")
        {
            header();
            addAchievements();
        }
        else if (adminOption == "8")
        {
            header();
            setTicketPrices();
        }
        else if (adminOption == "9")
        {
            header();
            checkTeam();
        }
        else if (adminOption == "10")
        {
            header();
            checkMgmtStaff();
        }
        else if (adminOption == "11")
        {
            header();
            changePlayerName();
        }
        else if (adminOption == "12")
        {
            header();
            scheduleMatch();
        }
    }
}

void playerInterface()
{
    string playerOption = "0";
    while (playerOption != "6")
    {
        system("cls");
        header();
        playerOption = playerMenu();
        system("cls");

        if (playerOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (playerOption == "2")
        {
            header();
            checkPlayingXI();
        }

        else if (playerOption == "3")
        {
            header();
            checkStats();
        }

        else if (playerOption == "4")
        {
            header();
            checkAchievements();
        }

        else if (playerOption == "5")
        {
            header();
            checkTrainingSchedule();
        }
    }
}

void coachInterface()
{
    string coachOption = "0";
    while (coachOption != "11")
    {
        system("cls");
        header();
        coachOption = coachMenu();
        system("cls");

        if (coachOption == "1")
        {
            header();
            addPlayer();
        }

        else if (coachOption == "2")
        {
            header();
            removePlayer();
        }

        else if (coachOption == "3")
        {
            header();
            searchPlayer();
        }

        else if (coachOption == "4")
        {
            header();
            checkSchedule();
        }

        else if (coachOption == "5")
        {
            header();
            checkTeam();
        }

        else if (coachOption == "6")
        {
            header();
            changePlayingX1();
        }

        else if (coachOption == "7")
        {
            header();
            checkStats();
        }

        else if (coachOption == "8")
        {
            header();
            scheduleTraining();
        }

        else if (coachOption == "9")
        {
            header();
            checkAchievements();
        }

        else if (coachOption == "10")
        {
            header();
            addPlayerPerformance();
        }
    }
}

void fanInterface()
{
    string fanOption = "0";
    while (fanOption != "4")
    {
        system("cls");
        header();
        fanOption = fanMenu();
        system("cls");

        if (fanOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (fanOption == "2")
        {
            header();
            checkStats();
        }

        else if (fanOption == "3")
        {
            header();
            checkAchievements();
        }
    }
}

void addPlayer()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        system("cls");
        header();
        cout << "Enter the player's name: ";
        getline(cin,clubPlayersName[currentPlayers]);
        cout << "Role(Batter / Bowler / WK / All-Rounder): ";
        getline(cin,clubPlayersRole[currentPlayers]);
        cout << "Batting style(Left / Right): ";
        getline(cin,clubPlayersBattingStyle[currentPlayers]);
        cout << "Bowling style(Left / Right / No): ";
        getline(cin,clubPlayersBowlingStyle[currentPlayers]);
        cout << "Enter the age of player: ";
        cin >> clubPlayersAge[currentPlayers];
        cout << "Enter his salary: ";
        cin >> clubPlayersSalary[currentPlayers];
        storeCricketersData(clubPlayersName[currentPlayers], clubPlayersRole[currentPlayers], clubPlayersBattingStyle[currentPlayers], clubPlayersBowlingStyle[currentPlayers], clubPlayersAge[currentPlayers], clubCoachesSalary[currentPlayers]);
        currentPlayers++;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit. " << endl
             << "Enter any other key to continue...";
        getline(cin,userEnter);
        
        getline(cin,userEnter);
    }
}

void removePlayer()
{
    string nameToRemove;
    string userEnter = "1";
    int ageRemove;
    while (userEnter != "0")
    {
        cout << "Enter the name of player you want to remove: ";
        getline(cin,nameToRemove);
        cout << "Enter his age: ";
        cin >> ageRemove;

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((nameToRemove == clubPlayersName[idx]) && (ageRemove == clubPlayersAge[idx]))
            {
                clubPlayersName[idx] = "";
                clubPlayersAge[idx] = 0;
                clubPlayersBattingStyle[idx] = "";
                clubPlayersBowlingStyle[idx] = "";
                clubPlayersRole[idx] = "";
                clubPlayersSalary[idx] = 0;
                currentPlayers--;
            }
        }
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);

    }
}

void checkFinances()
{
    int sumPlayer = 0;
    int sumCoach = 0;
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            sumPlayer = sumPlayer + clubPlayersSalary[idx];
        }
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            sumCoach = sumCoach + clubCoachesSalary[idx];
        }
        cout << "1. Player's Salary: " << sumPlayer << endl;
        cout << "2. Coach's Salary: " << sumCoach << endl;

        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void addCoach()
{
    string userEnter = "1";
    while (userEnter != "0")
    { 
        cout << "Enter the coach's name: ";
        getline(cin,clubCoachesName[currentCoaches]);
        cout << "Role(Head / Batting / Bowling / WK / Fielding): ";
        getline(cin,clubCoachesRole[currentCoaches]);
        cout << "Enter the age of coach: ";
        cin >> clubCoachesAge[currentCoaches];
        cout << "Enter his salary: ";
        cin >> clubCoachesSalary[currentCoaches];
        storeCoachesData(clubCoachesName[currentCoaches],clubCoachesRole[currentCoaches],clubCoachesAge[currentCoaches],clubCoachesSalary[currentCoaches]);
        currentCoaches++;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void removeCoach()
{
    string nameToRemove;
    string userEnter = "1";
    int ageRemove;
    while (userEnter != "0")
    {
        cout << "Enter the name of coach you want to remove: ";
        getline(cin,nameToRemove);
        cout << "Enter his age: ";
        cin >> ageRemove;

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((nameToRemove == clubCoachesName[idx]) && (ageRemove == clubCoachesAge[idx]))
            {
                clubCoachesName[idx] = "";
                clubCoachesAge[idx] = 0;
                clubCoachesRole[idx] = "";
                clubCoachesSalary[idx] = 0;
                currentCoaches--;
            }
        }
        cout << "Do you want to continue?" << endl
             << "Press 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);

    }
}

void addAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "Enter Achievements:-" << endl;
        for (int idx = 0; idx < achievements; idx++)
        {
            getline(cin,showAchievements[idx]);
        }
        storeAchievements(showAchievements[0], showAchievements[1],showAchievements[2],showAchievements[3],showAchievements[4]);
        cout << "Do you want to continue?" << endl
             << "Press 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void setTicketPrices()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "Set New Ticket Prices: ";
        cin >> newTicketPrices;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void checkTeam()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "     "
             << "Name"
             << "    "
             << "    Age"
             << "    "
             << "    Role"
             << "    "
             << "    Batting Style"
             << "    "
             << "    Bowling Style"
             << "    "
             << "    Salary" << endl;
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            cout << idx + 1 << ".    " << clubPlayersName[idx] << "    " << clubPlayersAge[idx] << "    " << clubPlayersRole[idx] << "    " << clubPlayersBattingStyle[idx] << "    " << clubPlayersBowlingStyle[idx] << "    " << clubPlayersSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void checkMgmtStaff()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "     "
             << "Name"
             << "    "
             << "Age"
             << "    "
             << "Role"
             << "    "
             << "Salary" << endl;
        for (int idx = 0; idx < clubCoaches; idx++)
        {
            cout << idx + 1 << ".   " << clubCoachesName[idx] << "   " << clubCoachesAge[idx] << "    " << clubCoachesRole[idx] << "   " << clubCoachesSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void searchPlayer()
{
    string search;
    bool flag = false;
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "Enter the player's name: ";
        getline(cin,search);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if (search == clubPlayersName[idx])
            {
                flag = true;
                cout << "The player is at index " << idx << endl;
                cout << "Player's Role: " << clubPlayersRole[idx] << endl;
                cout << "Player's Batting Style: " << clubPlayersBattingStyle[idx] << endl;
                cout << "Player's Bowling Style: " << clubPlayersBowlingStyle[idx] << endl;
                cout << "Player's Salary: " << clubPlayersSalary[idx] << endl;
            }
        }
        if (flag == false)
        {
            cout << "There is no such player in the team." << endl;
        }
        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void scheduleMatch()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber; idx++)
        {
            cout << "Match " << idx + 1 << endl;
            string a;
            getline(cin,a);
            cout << "Enter the opposite club name: ";
            getline(cin,oppositions[idx]);
            cout << "Date: ";
            getline(cin,dates[idx]);
            cout << "Time: ";
            getline(cin,times[idx]);
            cout << "Ground: ";
            getline(cin,grounds[idx]);
            storeSchedule(oppositions[idx],dates[idx],times[idx],grounds[idx]);
            cout << "Do you want to continue?" << endl
                 << "Press 0 to exit." << endl;
            string anykey = "2";
            cin >> anykey;
            if (anykey == "0")
            {
                break;
            }
        }
        cout << "Enter 0 to exit the menu." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void checkSchedule()
{
    string userEnter = "1";

    for (int idx = 0; idx < scheduleNumber; idx++)
    {
        cout << clubName << " vs " << oppositions[idx] << "       " << dates[idx] << "       " << times[idx] << "       " << grounds[idx] << endl;
    }

    cout << "Enter any key to exit.";
    getline(cin,userEnter);
}

void changePlayingX1()
{
    string userEnter = "1";
    int idx1, idx2, temp;
    string temp1;
    while (userEnter != "0")
    {
        cout << "Enter Player in playing XI(index): ";
        cin >> idx1;
        idx1 = idx1 - 1;
        cout << "Enter substitution player(index): ";
        cin >> idx2;
        idx2 = idx2 - 1;
        temp1 = clubPlayersName[idx1];
        clubPlayersName[idx1] = clubPlayersName[idx2];
        clubPlayersName[idx2] = temp1;

        temp = clubPlayersAge[idx1];
        clubPlayersAge[idx1] = clubPlayersAge[idx2];
        clubPlayersAge[idx2] = temp;

        temp1 = clubPlayersRole[idx1];
        clubPlayersRole[idx1] = clubPlayersRole[idx2];
        clubPlayersRole[idx2] = temp1;

        temp1 = clubPlayersBattingStyle[idx1];
        clubPlayersBattingStyle[idx1] = clubPlayersBattingStyle[idx2];
        clubPlayersBattingStyle[idx2] = temp1;

        temp1 = clubPlayersBowlingStyle[idx1];
        clubPlayersBowlingStyle[idx1] = clubPlayersBowlingStyle[idx2];
        clubPlayersBowlingStyle[idx2] = temp1;

        temp = clubPlayersSalary[idx1];
        clubPlayersSalary[idx1] = clubPlayersSalary[idx2];
        clubPlayersSalary[idx2] = temp;

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void changePlayerName()
{
    string userEnter = "1";
    string name, role;
    while (userEnter != "0")
    {

        cout << "Name of player which was recorded previously: ";
        getline(cin,name);
        cout << "His Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((name == clubPlayersName[idx]) && (role == clubCoachesRole[idx]))
            {
                string a;
                getline(cin,a);
                cout << "Write the corrected name: ";
                getline(cin,clubPlayersName[idx]);
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void addPlayerPerformance()
{
    string userEnter = "1";
    string name, role;
    float average;
    while (userEnter != "0")
    {
        cout << "Player's name: ";
        getline(cin,name);
        cout << "Player's Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((clubPlayersName[idx] == name) && (clubPlayersRole[idx] == role))
            {
                cout << "Enter his runs: ";
                cin >> clubPlayerRuns[idx];
                cout << "Nummber of innings: ";
                cin >> clubPlayerInnings[idx];
                cout << "Number of wickets: ";
                cin >> clubPlayerWickets[idx];
                cout << "Highest Score: ";
                cin >> clubPlayerHighScore[idx];
                average = clubPlayerRuns[idx] / clubPlayerInnings[idx];
                cout << "Average: " << average << endl;
                clubPlayerAverage[idx] = average;
                storeStatistics(clubPlayersName[idx], clubPlayersRole[idx], clubPlayerInnings[idx], clubPlayerRuns[idx], clubPlayerHighScore[idx], clubPlayerAverage[idx], clubPlayerWickets[idx]);
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void checkStats()
{
    string userEnter = "1";
    string name, role;
    while (userEnter != "0")
    {
        cout << "Player's Name: ";
        getline(cin,name);
        cout << "Player's Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((name == clubPlayersName[idx]) && (role == clubPlayersRole[idx]))
            {
                cout << "Player Name: " << name << endl;
                cout << "Player's Role: " << role << endl;
                cout << "Innings: " << clubPlayerInnings[idx] << endl;
                cout << "Runs: " << clubPlayerRuns[idx] << endl;
                cout << "Wickets: " << clubPlayerWickets[idx] << endl;
                cout << "Highest Score: " << clubPlayerHighScore[idx] << endl;
                cout << "Average: " << clubPlayerAverage[idx] << endl;
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
    }
}

void scheduleTraining()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "Enter Date: ";
            cin >> trainingDate[idx];
            cout << "Enter Time: ";
            cin >> trainingTime[idx];
            storeTrainingSchedule(trainingDate[idx],trainingTime[idx]);
        }

        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void checkAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < achievements; idx++)
        {
            cout << idx + 1 << ". " << showAchievements[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void checkPlayingXI()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < 11; idx++)
        {
            cout << idx + 1 << ". " << clubPlayersName[idx] << endl;
        }
        cout << "Enter 0 to exit.";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void checkTrainingSchedule()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "                       Date"
             << "        Time" << endl;
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "Training Session " << idx + 1 << ". " << trainingDate[idx] << "    " << trainingTime[idx] << endl;
        }
        cout << "Enter 0 to exit.";
        getline(cin,userEnter);
        getline(cin,userEnter);
    }
}

void storeData(string username, string password, string role)
{
    fstream file;
    file.open("Data.txt",ios::app);
    file << username << endl;
    file << password << endl;
    file << role << endl;
    file.close();
}

void addUser(string username, string password, string role)
{
    userArrName[usersCount] = username;
    userArrPassword[usersCount] = password;
    userArrRole[usersCount] = role;
    usersCount++;
}

void loadData()
{
    fstream file;
    string username, password, role;
    file.open("Data.txt",ios::in);
    while (getline(file,username) && getline(file,password) && getline(file,role))
    {    
    userArrName[usersCount] = username;
    userArrPassword[usersCount] = password;
    userArrRole[usersCount] = role;
    usersCount++;
    }
    file.close();
}

void storeStatistics(string name, string role, int innings, int runs, int highScore, int average, int wickets)
{
    fstream file;
    file.open("CricketersStats.txt",ios::app);
    file << name << "," << role << "," <<  innings << "," << runs << ","  << average << "," << highScore << "," << wickets << endl;
    file.close();
}

void loadStatistics()
{
    fstream file;
    string line;
    string tempName;
    string tempRole;
    file.open("CricketersStats.txt",ios::in);
    while(!file.eof())
    {
    getline(file,line);
    tempName = parseWord(line,1);
    tempRole = parseWord(line,2);
    for(int idx = 0 ; idx < 25; idx++)
    {
        if((clubPlayersName[idx] == tempName) && (clubPlayersRole[idx] == tempRole))
        {
            clubPlayerInnings[idx] = stoi(parseWord(line,3));
            clubPlayerRuns[idx] = stoi(parseWord(line,4));
            clubPlayerAverage[idx] = stof(parseWord(line,5));
            clubPlayerHighScore[idx] = stoi(parseWord(line,6));
            clubPlayerWickets[idx] = stoi(parseWord(line,7));
        }
    }
    }
    file.close();
}

string parseWord(string line, int field)
{
    int commaCount = 1;
    string reqdWord;
    for(int idx = 0; idx < line.length(); idx++)
    {
        if(line[idx] == ',')
        {
            commaCount++;
        }
        else if(commaCount == field)
        {
            reqdWord = reqdWord + line[idx];
        }
    }
    return reqdWord;
}

void storeCricketersData(string name, string role, string battingStyle, string bowlingStyle, int age, int salary)
{
    fstream file;
    file.open("CricketersData.txt",ios::app);
    file << endl;
    file << name << "," << role << ","  << battingStyle << "," << bowlingStyle << "," << age << "," << salary;
    file.close();
}

void storeCoachesData(string name, string role, int age, int salary)
{
    fstream file;
    file.open("CoachesData.txt",ios::app);
    file << name << "," << role << "," << age << "," << salary << endl;
    file.close();
}

void loadCoachesData()
{
    fstream file;
    string line;
    int idx = 0;
    currentCoaches = clubCoaches;
    file.open("CoachesData.txt",ios::in);
    while(!file.eof())
    {
    getline(file,line);
    
        clubCoachesName[idx] = parseWord(line,1);
        clubCoachesRole[idx] = parseWord(line,2);
        clubCoachesAge[idx] = stoi(parseWord(line,3));
        clubCoachesSalary[idx] = stoi(parseWord(line,4));
        idx++;
    }
    
    file.close();
}

void storeAchievements(string achievement1, string achievement2, string achievement3, string achievement4, string achievement5)
{
    fstream file;
    file.open("Achievements.txt",ios::out);
    {
        file << achievement1 << endl;
        file << achievement2 << endl;
        file << achievement3 << endl;
        file << achievement4 << endl;
        file << achievement5;
    }
    file.close();
}

void loadAchievements()
{
    fstream file;
    string line;
    int idx = 0;
    file.open("Achievements.txt",ios::in);
    while(!file.eof())
    {
        getline(file,line);
        showAchievements[idx] = line;
        idx++;
    }
    file.close();
}

void loadCricketersData()
{
    fstream file;
    string line;
    string age;
    string salary;
    int idx = 0;
    file.open("CricketersData.txt",ios::in);
    while(!file.eof())
    {
        getline(file,line);
        clubPlayersName[idx] = parseWord(line,1);
        clubPlayersRole[idx] = parseWord(line,2);
        clubPlayersBattingStyle[idx] = parseWord(line,3);
        clubPlayersBowlingStyle[idx] = parseWord(line,4);
        age = parseWord(line,5);
        clubPlayersAge[idx] = stoi(age);
        salary = parseWord(line,6);
        clubPlayersSalary[idx] = stoi(salary);
        idx++;    
    }
    file.close(); 
}

bool isValid(string username, string role)
{
    bool flag = true;
    for(int idx  = 0; idx < usersCount; idx++)
    {
        if(userArrName[idx] == username && userArrRole[idx] == role)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void storeSchedule(string opposition, string date, string time, string ground)
{
    fstream file;
    file.open("Schedule.txt",ios::app);
    file << opposition << "," << date << "," << time << "," << ground << endl;
    file.close();
}

void loadSchedule()
{
    fstream file;
    string line;
    int idx = 0;
    file.open("Schedule.txt",ios::in);
    while(!file.eof())
    {
        getline(file,line);
        oppositions[idx] = parseWord(line,1);
        dates[idx] = parseWord(line,2);
        times[idx] = parseWord(line,3);
        grounds[idx] = parseWord(line,4);
    }
    file.close();
}

void storeTrainingSchedule(string date, string time)
{
    fstream file;
    file.open("Training.txt,ios::app");
    file << date << "," << time << endl;
    file.close();
}

void loadTrainingSchedule()
{
    fstream file;
    int idx = 0;
    string line;
    file.open("Training.txt",ios::in);
    while(!file.eof())
    {
        getline(file,line);
        trainingDate[idx] = parseWord(line,1);
        trainingTime[idx] = parseWord(line,2);
        idx++;
    }
    file.close();
}
