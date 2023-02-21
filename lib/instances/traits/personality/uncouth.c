//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "uncouth");
    addSpecification("description", "You are rather unrefined and "
        "ill-mannered.");
    addSpecification("root", "crude");
    addSpecification("opposing root", "refined");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
}
