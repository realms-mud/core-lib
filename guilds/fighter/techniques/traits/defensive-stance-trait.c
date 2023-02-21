//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Offensive Stance");
    addSpecification("root", "offensive stance");
    addSpecification("description", "You are carefully poising your weapon "
        "in an offensive stance.");
        
    addSpecification("triggering research", 
        "/guilds/fighter/techniques/offensive-stance.c");
}
