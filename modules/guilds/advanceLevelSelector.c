//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string Guild;
private mapping ResearchChoices = ([]);
private int ChoicePresent = 0;

/////////////////////////////////////////////////////////////////////////////
public void setGuild(string guild)
{
    Guild = guild;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        Description = "Menu";
        Type = "Advancement";
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = sprintf("%s Menu", capitalize(Guild));

    Data = ([]);

    if (objectp(User) && Guild)
    {
        User->advanceLevel(Guild);

        if (User->attributePoints())
        {
            Data[to_string(sizeof(Data) + 1)] = ([
                "name":"Spend Attribute Points",
                "type": "attributes",
                "description": "This option lets you spend points on new attributes.\n",
                "canShow": 1
            ]);
        }

        if (User->AvailableSkillPoints())
        {
            Data[to_string(sizeof(Data) + 1)] = ([
                "name":"Spend Skill Points",
                "type": "skills",
                "description": "This option lets you spend points on new attributes.\n",
                "canShow": 1
            ]);
        }

        ResearchChoices = User->getResearchChoices();
        if (sizeof(ResearchChoices))
        {
            ChoicePresent = 1;
            foreach(string choice in m_indices(ResearchChoices))
            {
                int canChoose = 1;
                if (member(ResearchChoices[choice], "1") && 
                    member(ResearchChoices[choice]["1"], "dependency"))
                {

                    foreach(string item in ResearchChoices[choice]["1"]["dependency"])
                    {
                        canChoose &&= ((member(User->availableResearchTrees(),
                            item) > -1) || User->isResearched(item));
                    }

                    if (!canChoose)
                    {
                        canChoose =
                            User->canResearch(ResearchChoices[choice]["1"]["key"]);
                    }
                }
                Data[to_string(sizeof(Data) + 1)] = ([
                    "name": sprintf("Research Choice: %s", choice),
                    "type": "research choice",
                    "title": choice,
                    "data": ResearchChoices[choice],
                    "description": "This option lets you select from a list of granted research.\n",
                    "canShow": canChoose
                ]);
            }
        }
        else
        {
            ChoicePresent = 0;
        }

        if (User->researchPoints())
        {
            Data[to_string(sizeof(Data) + 1)] = ([
                "name":"Spend Research Points",
                "type": "research",
                "description": "This option lets you spend points on new attributes.\n",
                "canShow": 1,
                "choose research": ChoicePresent
            ]);
        }
    }

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Advancement Menu",
        "type": "exit",
        "description": "This option lets you exit the guild advancement menu.\n",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret && Data[selection]["canShow"])
        {
            switch (Data[selection]["type"])
            {
                case "attributes":
                {
                    SubselectorObj =
                        clone_object("/lib/modules/creation/attributeSelector.c");
                    SubselectorObj->advanceLevel();
                    break;
                }
                case "skills":
                {
                    SubselectorObj =
                        clone_object("/lib/modules/creation/skillsSelector.c");
                    SubselectorObj->advanceLevel();
                    break;
                }
                case "research choice":
                {
                    SubselectorObj =
                        clone_object("/lib/modules/guilds/researchChooser.c");
                    SubselectorObj->setResearchTitle(Data[selection]["title"], this_object());
                    move_object(SubselectorObj, User);
                    SubselectorObj->registerEvent(this_object());
                    SubselectorObj->onResearchChoiceAvailable(User,
                        Data[selection]["data"]);
                    break;
                }
                case "research":
                {
                    SubselectorObj =
                        clone_object("/lib/modules/research/researchSubselector.c");
                    SubselectorObj->setSource(sprintf("%s Guild", Guild));
                    SubselectorObj->setPointsRemaining(User->researchPoints());
                    break;
                }
            }

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
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayText = configuration->decorate("%s", "choice enabled",
        "selector", colorConfiguration);
    if (member(Data[choice], "choose research") &&
        Data[choice]["choose research"])
    {
        displayText = configuration->decorate("%-40s ", "choice disabled",
            "selector", colorConfiguration) +
            configuration->decorate("(Select Choices First)", "note", "selector",
                colorConfiguration);
    }
    else if (!Data[choice]["canShow"])
    {
        displayText = configuration->decorate("%-40s ", "choice disabled",
            "selector", colorConfiguration) +
            configuration->decorate("(Prerequisite Missing)", "note", "selector",
                colorConfiguration);
    }

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice), displayText, displayDetails(choice));
}
