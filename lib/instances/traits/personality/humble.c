//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "humble");
    addSpecification("description", "You tend show a great deal of "
        "modesty surrounding your accomplishments and level of worth.");
    addSpecification("root", "humble");
    addSpecification("opposing root", "arrogant");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", 5);
}
