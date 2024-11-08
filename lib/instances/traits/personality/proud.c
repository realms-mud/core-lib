//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "proud");
    addSpecification("description", "You have an excessively high "
        "opinion about yourself - your accomplishments and your "
        "importance.");
    addSpecification("root", "arrogant");
    addSpecification("opposing root", "humble");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
