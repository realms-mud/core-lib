//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "malicious");
    addSpecification("description", "You tend to try to control "
        "others to suit your purpose typically through unscrupulous "
        "and/or disengenuous means.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
    addSpecification("bonus persuasion", 1);
}
