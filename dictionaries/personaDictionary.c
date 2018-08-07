//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

#include "personas/fighters.h"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping personaBlueprints()
{
    return fighterBlueprints + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetPrimarySkills(object character, string persona)
{
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetSecondarySkills(object character, string persona)
{
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetTraits(object character, string persona)
{
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetRandomTraits(object character, string persona)
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setupPersona(object character)
{
    if (objectp(character) &&
        ((member(inherit_list(character), "lib/realizations/monster.c") > -1) ||
        (member(inherit_list(character), "lib/realizations/henchman.c") > -1)))
    {
        if (!character->effectiveLevel())
        {
            raise_error("personaDictionary: The character's level must be set "
                "before a persona is selected.");
        }

        string persona = character->queryProperty("persona");
        if (persona && member(personaBlueprints(), persona))
        {
            SetPrimarySkills(character, persona);
            SetSecondarySkills(character, persona);
            SetTraits(character, persona);
            SetRandomTraits(character, persona);
        }
        else
        {
            raise_error("personaDictionary: An invalid persona was selected.");
        }
    }
    else
    {
        raise_error("personaDictionary: Personas can only be set for NPCs.\n");
    }
}
