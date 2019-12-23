//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "effect");
        addSpecification("name", "Nectar of Echlarhol");
        addSpecification("description", "You have quaffed the 'Nectar of "
            "Echlarhol' potion and are currently benefitting from its effects.");
        addSpecification("root", "healthy");
        addSpecification("opposing root", "infirm");
        addSpecification("opinion", 10);
        addSpecification("duration", 300);
        addSpecification("bonus spell points", 200);        
        addSpecification("expire message", "The effects of the 'Nectar of "
            "Echlarhol' potion subside.");
        "baseTrait"::reset(arg);
    }
}
