//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "persuasive");
        addSpecification("description", "You are very good at convincing "
            "others of your deeply-held convictions.");
        addSpecification("root", "persuasive");
        addSpecification("opinion", 5);
        addSpecification("bonus persuasion", 3);
        "baseTrait"::reset(arg);
    }
}
