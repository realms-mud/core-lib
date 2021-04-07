//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Calculated Attack");
    addSpecification("root", "do not attack");
    addSpecification("description", "You are carefully poising your weapon. "
        "While this is in effect, you cannot attack, but your blade "
        "skills will receive a bonus dependent on how long you have "
        "taken to attack.");
        
    addSpecification("triggering research", 
        "guilds/fighter/blades/calculated-attack.c");
}
