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
        addSpecification("name", "irascible");
        addSpecification("description", "People are annoying. You tend to "
            "have a fairly short fuse when confronted with said annoyances.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
