//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "chivalrous");
    addSpecification("description", "You are corteous and gallant.");
    addSpecification("root", "kind");
    addSpecification("opposing root", "malicious");
    addSpecification("opinion", 20);
    addSpecification("opposing opinion", -5);
    addSpecification("bonus etiquette", 1);
}
