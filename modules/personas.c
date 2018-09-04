//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave int researchFrequency = 35;

/////////////////////////////////////////////////////////////////////////////
private void setMonsterLevel(int level)
{
    call_direct(this_object(), "effectiveLevel", level);
}

/////////////////////////////////////////////////////////////////////////////
private void setHenchmanLevel(int level)
{
    // Need to implement in task 226
}

/////////////////////////////////////////////////////////////////////////////
private void setPersonaLevel(int level)
{
    if (getService("monster"))
    {
        setMonsterLevel(level);
    }
    else if (getService("henchman"))
    {
        setHenchmanLevel(level);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void SetUpPersonaOfLevel(string persona, int level)
{
    object livingObj = getService("living");
    if (livingObj)
    {
        setPersonaLevel(level);
        getDictionary("persona")->setupPersona(persona, this_object());
    }
    else
    {
        raise_error("Personas: Cannot set up a persona on a non-living object.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setUpRandomEquipment(int chanceForMagicalItems)
{
    object livingObj = getService("living");
    if (livingObj)
    {
        object *equipment = getDictionary("persona")->getRandomEquipment(this_object(),
            chanceForMagicalItems);

        foreach(object item in equipment)
        {
            move_object(item, livingObj);
            livingObj->equip(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void executePersonaResearch(string target, string specificResearch)
{
    object research = getService("research");
    if (objectp(research) && (random(100) < researchFrequency))
    {
        string *potentialResearchItems = filter(research->completedResearch(),
            (: getDictionary("research")->isActiveOrSustainedAbility($1) :));

        if (sizeof(potentialResearchItems))
        {
            string researchItemString = specificResearch ? specificResearch :
                potentialResearchItems[random(sizeof(potentialResearchItems))];

            object researchItem =
                getDictionary("research")->researchObject(researchItemString);

            if (researchItem)
            {
                string *commandList = researchItem->commandList();
                if (sizeof(commandList))
                {
                    string commandString = commandList[0];
                    if (researchItem->query("effect") == "beneficial")
                    {
                        commandString = regreplace(commandString,
                            "at ##Target##", sprintf("at %s",
                                this_object()->RealName() || ""), 1);
                    }
                    else
                    {
                        commandString = regreplace(commandString,
                            "##Target##", target, 1);
                    }
                    research->researchCommand(commandString);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setResearchFrequency(int newFrequency)
{
    if (intp(newFrequency) && (newFrequency >= 0) && (newFrequency <= 100))
    {
        researchFrequency = newFrequency;
    }
}
