//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shoe last");
    addAlias("last");
    addAlias("cobbler's last");
    addAlias("boot form");

    addAdjectives(({ "wooden", "foot-shaped", "polished", "well-worn",
        "old", "various", "smooth", "carved", "sturdy", "assorted" }));

    addDescriptionTemplate("##Adjective## shoe lasts arranged on a shelf");

    addItemTemplate(
        "The shoe lasts are foot-shaped blocks of hardwood, each carved "
        "to a different size and smoothed to a satin finish by years of "
        "use. They are arranged in neat rows on a shelf, from children's "
        "sizes to large men's, and a few are shaped for women's pointed "
        "shoes. Scraps of leather and thread cling to several of them."
    );

    addSomeLightDescriptionTemplate(
        "rows of wooden shoe lasts line a shelf, smooth and foot-shaped"
    );
    addDimLightDescriptionTemplate(
        "rows of pale wooden forms sit on a shelf, their shapes distinctive"
    );
    addLowLightDescriptionTemplate(
        "rows of smooth wooden shapes line a shelf"
    );
    addNearDarkDescriptionTemplate(
        "the smell of leather and cobbler's wax fills the air"
    );
}
