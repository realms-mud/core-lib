//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Defensive Stance");
    addSpecification("root", "defensive stance");
    addSpecification("description", "You are carefully poising your weapon "
        "in a defensive stance.");
        
    addSpecification("triggering research", 
        "/guilds/fighter/techniques/defensive-stance.c");
}
