//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private int TotalPoints;
private int TestTaken = 0;
private string *UndoDetails = ({ });
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        Description = "From this menu, you can choose your character's traits";
        Data = ([
            "1":([
                "name": "Take Personality Test",
                "type": "personality",
                "description": "This option takes you through a series of questions that\n"
                    "are used to identify your character's personality.\n"
            ]),
            "2":([
                "name": "Educational Traits",
                "type" : "educational",
                "description": "Educational traits are learned traits - those that\n"
                    "have been cultivated both through formal learning as well as\n"
                    "those uncovered as a result of either success or failure to learn.\n"
            ]),
            "3":([
                "name": "Genetic Traits",
                "type" : "genetic",
                "description": "Genetic traits are those traits you have inherited the disposition for\n"
                    "by your ancestors.\n"
            ]),
            "4":([
                "name": "Health Traits",
                "type" : "health",
                "description": "Health traits are those genetic traits that are specifically related to\n"
                    "your physical and mental health.\n"
            ]),
            "5":([
                "name": "Sexuality Traits",
                "type" : "sexuality",
                "description": "Sexuality traits are those traits that deal with sexual identity.\n"
            ]),
            "6":([
                "name": "Exit Trait Selection   \x1b[0;31;1m(You will lose unspent trait points!)\x1b[0m",
                "type" : "exit",
                "description": "This option lets you exit the trait selection menu.\n"
            ]),
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object racialDictionary = load_object("/lib/dictionaries/racialDictionary.c");

    TotalPoints = racialDictionary->backgroundTraitPoints(User->Race());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if ((Data[choice]["type"] == "personality") && TestTaken)
    {
        ret = "\x1b[0;34;1m  (Completed)\x1b[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    string ret = "";
    if (TotalPoints > 0)
    {
        ret += sprintf("You have %d trait points left to assign.\n", TotalPoints);
    }
    if (!TestTaken)
    {
        ret += "You have not yet taken the personality test.\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        if (!ret)
        {
            if (TestTaken && (Data[selection]["type"] == "personality"))
            {
                tell_object(User, "You have already taken the personality test.\n");
            }
            else
            {
                string selector = sprintf("/lib/modules/creation/%sTraitSelector.c",
                    lower_case(Data[selection]["type"]));

                SubselectorObj = clone_object(selector);
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->setPointsRemaining(TotalPoints);
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        if (stringp(caller->selection()))
        {
            UndoDetails += ({ caller->selection() });
            TotalPoints -= load_object("/lib/dictionaries/traitsDictionary.c")->
                traitObject(caller->selection())->query("cost");
        }

        if (!TestTaken)
        {
            TestTaken = caller->testTaken();
        }
    }

    if (TotalPoints || !TestTaken)
    {
        tell_object(User, displayMessage());
    }
    else
    {
        notifySynchronous("onSelectorCompleted");
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void undoSelection(string selection)
{
    if (User && sizeof(UndoDetails))
    {
        string traitToRemove = UndoDetails[sizeof(UndoDetails) - 1];

        if (sizeof(UndoDetails) > 1)
        {
            UndoDetails = UndoDetails[0..(sizeof(UndoDetails) - 2)];
        }
        else
        {
            UndoDetails = ({});
        }
        User->removeTrait(traitToRemove);
        TotalPoints += load_object("/lib/dictionaries/traitsDictionary.c")->
            traitObject(traitToRemove)->query("cost");
    }
}
