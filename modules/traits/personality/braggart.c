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
        addSpecification("name", "braggart");
        addSpecification("description", "You sure do love to tell a good "
            "tale - especially when the tale involves all of your amazing "
            "accomplishments!");
        addSpecification("root", "braggart");
        addSpecification("opposing root", "humble");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}
