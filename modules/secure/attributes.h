//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
// Flag to determine if an attribute is overwritten or incremented
private nosave int IncrementAttribute = 1;

private int strength;
private int intelligence;
private int dexterity;
private int wisdom;
private int constitution;
private int charisma;
private int availableAttributePoints;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadAttributes(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        strength = persistence->extractSaveData("strength", data);
        intelligence = persistence->extractSaveData("intelligence", data);
        dexterity = persistence->extractSaveData("dexterity", data);
        wisdom = persistence->extractSaveData("wisdom", data);
        constitution = persistence->extractSaveData("constitution", data);
        charisma = persistence->extractSaveData("charisma", data);
        availableAttributePoints = persistence->extractSaveData("availableAttributePoints", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendAttributes()
{
    return ([
        "strength": strength,
        "intelligence": intelligence,
        "dexterity": dexterity,
        "wisdom": wisdom,
        "constitution": constitution,
        "charisma": charisma,
        "availableAttributePoints": availableAttributePoints
    ]);
}
