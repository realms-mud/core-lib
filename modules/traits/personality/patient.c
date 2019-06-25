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
        addSpecification("name", "patient");
        addSpecification("description", "You have an almost herculean "
            "ability to tolerate issues that come up without becoming "
            "annoyed or anxious.");
        addSpecification("root", "patient");
        addSpecification("opinion", 15);
        "baseTrait"::reset(arg);
    }
}
