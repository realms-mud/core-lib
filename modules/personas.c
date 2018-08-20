//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

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
