//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "sustained effect");
        addSpecification("name", "Mana Shield");
        addSpecification("root", "mana shield");
        addSpecification("description", "You are surrounded by a mana shield.");
        
        addSpecification("triggering research", 
            "lib/guilds/scion/common/mana-shield/root.c");

        "baseTrait"::reset(arg);
    }
}
