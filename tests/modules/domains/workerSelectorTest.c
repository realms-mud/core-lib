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
void SetupHenchmen()
{
    Player->addHenchman("argalach castle", ([
        "name": "Tirian",
        "house": "Arthellyn",
        "gender": "male",
        "type": "architect",
         "traits": ({ "lib/instances/traits/domains/master-architect.c" }),
       "persona": "swordsman",
        "level": 12,
        "activity": "idle"
    ]));

    Player->addHenchman("argalach castle", ([
        "name": "Beren",
        "house": "Marannuminas",
        "gender": "male",
        "type": "architect",
        "persona": "swordsman",
        "level": 10,
        "activity": "building"
    ]));

    Player->addHenchman("argalach castle", ([
        "name": "Derek",
        "house": "Evendim",
        "gender": "male",
        "type": "craftsman",
        "traits": ({ "lib/instances/traits/domains/journeyman-carpenter.c" }),
        "persona": "swordsman",
        "level": 10,
        "activity": "building"
    ]));
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/workerSelector.c");
    Selector->setLocation("argalach castle");
    Selector->setQuantityNeeded(1);
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
    SetupHenchmen();

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn                \n"
        "[3] - Confirm Selections       N/A    [4] - Exit Building Menu              \n"
        "You must select a number from 1 to 4.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingWorkerActsAsToggle()
{
    SetupHenchmen();

    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn                \n"
        "[3] - Confirm Selections       N/A    [4] - Exit Building Menu              \n"
        "You must select a number from 1 to 4.\n"
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
        "    Tirian Arthellyn         Benefits: \n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tirian Arthellyn            (*) \n"
        "[3] - Confirm Selections              [4] - Exit Building Menu              \n"
        "You must select a number from 1 to 4.\n"
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
        "[3] - Confirm Selections       N/A    [4] - Exit Building Menu              \n"
        "You must select a number from 1 to 4.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectMoreWorkersThanNeeded()
{
    SetupHenchmen();

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
        "    Tirian Arthellyn         Benefits: \n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tantor The Unclean              \n"
        "[3] - Tirian Arthellyn            (*) [4] - Confirm Selections              \n"
        "[5] - Exit Building Menu              \n"
        "You must select a number from 1 to 5.\n"
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
        "    Tirian Arthellyn         Benefits: \n\n"
        "[1] - Beren Marannuminas       busy   [2] - Tantor The Unclean              \n"
        "[3] - Tirian Arthellyn            (*) [4] - Confirm Selections              \n"
        "[5] - Exit Building Menu              \n"
        "You must select a number from 1 to 5.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 0 workers left to assign.\n",
        Player->caughtMessage());
}
