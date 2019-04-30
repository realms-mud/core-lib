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
        addSpecification("name", "envious");
        addSpecification("description", "You want it all. You want it now. "
            "You covet what others have.");
        addSpecification("root", "malicious");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}
