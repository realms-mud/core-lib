//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector";

private int TotalSkills;
private string *UndoDetails = ({ });
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        Description = "Choose a class of skills to advance";
        Data = ([
            "1":([
                "name": "Combat",
                "description": "Combat skills include all of those skills that allow one to\n"
                    "effectively use weapons, wear armor, and dodge or parry attacks\n"
            ]),
            "2":([
                "name": "Crafting",
                "description": "Crafting skills include all those skills that allow one to create,\n"
                    "identify, and maintain items within a specific discipline.\n"
            ]),
            "3":([
                "name": "Erudite",
                "description": "Erudite skils are knowledge-based skills - whether those are scientific\n"
                    "in nature, history of things, a general understanding of how\n"
                    "languages work, basic engineering principles, and spellcraft.\n"
            ]),
            "4":([
                "name": "General",
                "description": "General skills are those skills that do not neatly fall into one of\n"
                    "the other categories. Many profession-based and survival skills\n"
                    "fall in this category.\n"
            ]),
            "5":([
                "name": "Language",
                "description": "Theses skills provide the basis for speaking, reading, and writing\n"
                    "in a specific language. If you wish to interact with the denizens\n"
                    "of the game in ways more meaningful than bashing them in the face\n"
                    "with a club, these skills will be critical.\n"
            ]),
            "6":([
                "name": "Magic",
                "description": "Magic skills provide the ability to protect from and manipulate\n"
                    "the various forms that magic can take.\n"
            ]),
            "7":([
                "name": "Subterfuge",
                "description": "Subterfuge skills are those skills that deal with uncovering\n"
                    "and perpetrating deception. Several other dexterity and wit-based\n"
                    "skills are also included.\n"
            ]),
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object racialDictionary = load_object("/lib/dictionaries/racialDictionary.c");

    TotalSkills = (User->Int() / 2) +
        racialDictionary->startingSkillPoints(User->Race());

    User->addSkillPoints(TotalSkills * 2);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return sprintf("You have %d skills left to assign.\n", TotalSkills);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = TotalSkills == 0;
        if (!ret)
        {
            string selector = sprintf("/lib/modules/creation/%sSkillSelector.c",
                lower_case(Data[selection]["name"]));

            SubselectorObj = clone_object(selector);
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        UndoDetails += ({ caller->selection() });
        TotalSkills--;
    }
    caller->cleanUp();

    if (TotalSkills)
    {
        tell_object(User, displayMessage());
    }
    else
    {
        notify("onSelectorCompleted");
    }
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
        string skillToDecrement = UndoDetails[sizeof(UndoDetails) - 1];

        if (sizeof(UndoDetails) > 1)
        {
            UndoDetails = UndoDetails[0..(sizeof(UndoDetails) - 2)];
        }
        else
        {
            UndoDetails = ({});
        }
        User->decrementSkill(skillToDecrement, 1);
        TotalSkills++;
    }
}
