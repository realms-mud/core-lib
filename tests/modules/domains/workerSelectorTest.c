//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetupHenchmen" });
}

/////////////////////////////////////////////////////////////////////////////
void SetupHenchmen(string type)
{
    switch (type)
    {
        case "architect":
        {
            Player->addHenchman("argalach castle", ([
                "name": "Tirian",
                "house": "Arthellyn",
                "gender": "male",
                "type": "architect",
                "traits": ({ "lib/instances/traits/domains/journeyman-architect.c" }),
                "persona": "swordsman",
                "level": 12,
                "activity": "idle"
            ]));

            Player->addHenchman("argalach castle", ([
                "name": "Beren",
                "house": "Marannuminas",
                "gender": "male",
                "type": "architect",
                "traits": ({ "lib/instances/traits/domains/master-architect.c" }),
                "persona": "swordsman",
                "level": 10,
                "activity": "building"
            ]));
            break;
        }
        case "carpenter":
        {
            Player->addHenchman("argalach castle", ([
                "name": "Derek",
                "house": "Evendim",
                "gender": "male",
                "type": "carpenter",
                "traits": ({ "lib/instances/traits/domains/journeyman-carpenter.c" }),
                "persona": "swordsman",
                "level": 10,
                "activity": "building"
            ]));
            Player->addHenchman("argalach castle", ([
                "name": "Royce",
                "house": "Eralkidh",
                "gender": "male",
                "type": "carpenter",
                "traits": ({ "lib/instances/traits/domains/journeyman-carpenter.c" }),
                "persona": "swordsman",
                "level": 10,
                "activity": "idle"
            ]));
            Player->addHenchman("argalach castle", ([
                "name": "Marik",
                "house": "Argalen",
                "gender": "male",
                "type": "carpenter",
                "traits": ({ "lib/instances/traits/domains/master-carpenter.c" }),
                "persona": "swordsman",
                "level": 10,
                "activity": "idle"
            ]));
            Player->addHenchman("argalach castle", ([
                "name": "Arnalt",
                "house": "Arator",
                "gender": "male",
                "type": "carpenter",
                "traits": ({ "lib/instances/traits/domains/apprentice-carpenter.c" }),
                "persona": "swordsman",
                "level": 5,
                "activity": "idle"
            ]));
            break;
        }
    }

}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/workerSelector.c");
    Selector->setLocation("argalach castle");
    Selector->setQuantityNeeded(1);
    Selector->setDuration(500);
    Selector->setWorkerType("architect");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");
    Player->addPlayerHolding("argalach castle");

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Selector);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysWorkerSelectionMenu()
{
    SetupHenchmen("architect");

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn                \n"
        "[3] - Hire Apprentice ($12500) low $  [4] - Hire Architect ($112500) low $  \n"
        "[5] - Confirm Selections       N/A    [6] - Exit Building Menu              \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingWorkerActsAsToggle()
{
    SetupHenchmen("architect");

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn                \n"
        "[3] - Hire Apprentice ($12500) low $  [4] - Hire Architect ($112500) low $  \n"
        "[5] - Confirm Selections       N/A    [6] - Exit Building Menu              \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());

    command("2", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nAll required architects have been assigned.\n"
        "Select 'Confirm Selections' to continue.\n"
        "    Tirian Arthellyn         No bonuses or penalties\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn            (*) \n"
        "[3] - Hire Apprentice ($12500) low $  [4] - Hire Architect ($112500) low $  \n"
        "[5] - Confirm Selections              [6] - Exit Building Menu              \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 0 workers left to assign.\n",
        Player->caughtMessage());

    command("2", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn                \n"
        "[3] - Hire Apprentice ($12500) low $  [4] - Hire Architect ($112500) low $  \n"
        "[5] - Confirm Selections       N/A    [6] - Exit Building Menu              \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectMoreWorkersThanNeeded()
{
    SetupHenchmen("architect");

    Player->addHenchman("argalach castle", ([
        "name": "Tantor the Unclean",
        "gender": "male",
        "type": "architect",
        "persona": "swordsman",
        "level": 10,
        "activity": "idle"
    ]));

    Selector->initiateSelector(Player);
    command("3", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nAll required architects have been assigned.\n"
        "Select 'Confirm Selections' to continue.\n"
        "    Tirian Arthellyn         No bonuses or penalties\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tantor The Unclean              \n"
        "[3] - Tirian Arthellyn            (*) [4] - Hire Apprentice ($12500) low $  \n"
        "[5] - Hire Architect ($112500) low $  [6] - Confirm Selections              \n"
        "[7] - Exit Building Menu              \n"
        "You must select a number from 1 to 7.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 0 workers left to assign.\n",
        Player->caughtMessage());

    command("2", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nAll required architects have been assigned.\n"
        "Select 'Confirm Selections' to continue.\n"
        "    Tirian Arthellyn         No bonuses or penalties\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tantor The Unclean              \n"
        "[3] - Tirian Arthellyn            (*) [4] - Hire Apprentice ($12500) low $  \n"
        "[5] - Hire Architect ($112500) low $  [6] - Confirm Selections              \n"
        "[7] - Exit Building Menu              \n"
        "You must select a number from 1 to 7.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 0 workers left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectDetailsDisplayedForSelectedWorkers()
{
    SetupHenchmen("carpenter");
    Selector->setQuantityNeeded(3);
    Selector->setWorkerType("carpenter");

    Selector->initiateSelector(Player);
    command("3", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nCarpenters selected: 1 of 3.\n"
        "    Marik Argalen            M: +17%, D: +17%, C: +10%, U: +10%, S: +15%\n\n"
        "[1] - Arnalt Arator                   [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen               (*) [4] - Royce Eralkidh                  \n"
        "[5] - Hire Apprentice ($12500) low $  [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections       N/A    [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 2 workers left to assign.\n",
        Player->caughtMessage());

    command("1", Player);
    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nCarpenters selected: 2 of 3.\n"
        "    Arnalt Arator            M: -5%, D: -5%, C: -5%, U: -5%, S: -5%\n"
        "    Marik Argalen            M: +17%, D: +17%, C: +10%, U: +10%, S: +15%\n\n"
        "[1] - Arnalt Arator               (*) [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen               (*) [4] - Royce Eralkidh                  \n"
        "[5] - Hire Apprentice ($12500) low $  [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections       N/A    [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());

    command("4", Player);
    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nAll required carpenters have been assigned.\n"
        "Select 'Confirm Selections' to continue.\n"
        "    Arnalt Arator            M: -5%, D: -5%, C: -5%, U: -5%, S: -5%\n"
        "    Marik Argalen            M: +17%, D: +17%, C: +10%, U: +10%, S: +15%\n"
        "    Royce Eralkidh           No bonuses or penalties\n\n"
        "[1] - Arnalt Arator               (*) [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen               (*) [4] - Royce Eralkidh              (*) \n"
        "[5] - Hire Apprentice ($12500) low $  [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections              [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 0 workers left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanHireAWorker()
{
    Player->addMoney(12500);
    SetupHenchmen("carpenter");
    Selector->setQuantityNeeded(3);
    Selector->setWorkerType("carpenter");

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nCarpenters selected: 0 of 3.\n\n"
        "[1] - Arnalt Arator                   [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen                   [4] - Royce Eralkidh                  \n"
        "[5] - Hire Apprentice ($12500)        [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections       N/A    [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 3 workers left to assign.\n",
        Player->caughtMessage());

    command("5", Player);

    string addedCharacter = regreplace(Player->caughtMessage(),
        ".*    ([A-Za-z]+ [A-Za-z]+).*", "\\1", 1);
    string newEntry = regreplace(Player->caughtMessage(),
        ".*([0-9]+). - " + addedCharacter + ".*", "\\1", 1);

    ExpectSubStringMatch(sprintf("Carpenters selected: 1 of 3.*"
        "%s.*M: -5%%, D: -5%%, C: -5%%, U: -5%%, S: -5%%.*%s. - %s.*"
        "Hire Apprentice ..12500. low.*2 workers", 
        addedCharacter, newEntry, addedCharacter), 
        Player->caughtMessage());

    command(newEntry, Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nCarpenters selected: 0 of 3.\n\n"
        "[1] - Arnalt Arator                   [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen                   [4] - Royce Eralkidh                  \n"
        "[5] - Hire Apprentice ($12500)        [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections       N/A    [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 3 workers left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionShowsWorkDetails()
{
    SetupHenchmen("carpenter");
    Selector->setQuantityNeeded(3);
    Selector->setWorkerType("carpenter");

    Selector->initiateSelector(Player);
    command("? 3", Player);

    ExpectEq("This option assigns Marik Argalen to the task of building the selected\n"
        "component.\n"
        "Stats:\n"
        "    Name  : Marik Argalen\n"
        "    Traits: Master Carpenter, Swordsman\n"
        "    Skills:\n"
        "        Carpentry: 25\n"
        "        Wood Crafting: 20\n"
        "Domain Modifiers - This worker will have the following project-level effects:\n"
        "This person reduces the duration by 17% on this project.\n"
        "This person reduces the materials used by 17% on this project.\n"
        "This person increases the structural strength by 15% on this project.\n"
        "This person increases the units accomodated by 10% on this project.\n"
        "This person increases the combat modifiers by 10% on this project.\n"
        "This person is considered an elite worker for this project.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionShowsWorkDetailsWhenNotInSameLocation()
{
    SetupHenchmen("carpenter");
    Selector->setLocation("durthan castle");
    Selector->setQuantityNeeded(3);
    Selector->setWorkerType("carpenter");

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the carpenters who will be executing your\n"
        "project in your holdings at Durthan Castle.\n"
        "\nCarpenters selected: 0 of 3.\n\n"
        "[1] - Arnalt Arator               (R) [2] - Derek Evendim            busy   \n"
        "[3] - Marik Argalen               (R) [4] - Royce Eralkidh              (R) \n"
        "[5] - Hire Apprentice ($12500) low $  [6] - Hire Carpenter ($112500) low $  \n"
        "[7] - Confirm Selections       N/A    [8] - Exit Building Menu              \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 3 workers left to assign.\n",
        Player->caughtMessage());

    command("? 3", Player);

    ExpectEq("This option assigns Marik Argalen to the task of building the selected\n"
        "component.\n"
        "Stats:\n"
        "    Name  : Marik Argalen\n"
        "    Traits: Master Carpenter, Swordsman\n"
        "    Skills:\n"
        "        Carpentry: 25\n"
        "        Wood Crafting: 20\n"
        "Domain Modifiers - This worker will have the following project-level effects:\n"
        "This person increases the duration by 8% on this project.\n"
        "This person reduces the materials used by 17% on this project.\n"
        "This person increases the structural strength by 15% on this project.\n"
        "This person increases the units accomodated by 10% on this project.\n"
        "This person increases the combat modifiers by 10% on this project.\n"
        "This person is considered an elite worker for this project.\n"
        "The duration is increased because this person is not at Durthan Castle.\n",
        Player->caughtMessage());
}
