//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    addSpecification("type", "personality");
    addSpecification("name", "austere");
    addSpecification("description", "You have a rather severe or strict manner "
        "about you and this typically seeps into your attitiude toward others.");
    addSpecification("root", "harsh");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    "baseTrait"::reset(arg);
}
