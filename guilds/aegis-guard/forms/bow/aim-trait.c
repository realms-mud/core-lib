//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Careful Aim");
    addSpecification("root", "do not attack");
    addSpecification("description", "You are carefully aiming your bow. "
        "While this is in effect, you cannot attack, but your archery "
        "skills will receive a bonus dependent on how long you have "
        "taken to aim.");
        
    addSpecification("triggering research", 
        "guilds/aegis-guard/forms/bow/meitha-ture.c");
}
