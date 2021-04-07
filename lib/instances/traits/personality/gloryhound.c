//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "gloryhound");
    addSpecification("description", "You seek recognition as a doer of "
        "great deeds and go out of your way to achieve them - or at "
        "least convince others that you have.");
    addSpecification("root", "braggart");
    addSpecification("opposing root", "humble");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
}
