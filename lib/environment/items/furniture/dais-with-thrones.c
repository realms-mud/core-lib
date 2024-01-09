//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dais with thrones");
    addAlias("dais");
    addAlias("throne");
    addAlias("thrones");

    addAdjectives(({ "a once-grand, but now fallen in disrepair ",
        "a crumbling pale, gray-blue",
        "a disintegrating, but still imposing",
        "a long-neglected" }));

    addNearDarkDescriptionTemplate("the faint outline of two objects");
    addLowLightDescriptionTemplate("two objects that are roughly human-sized");
    addDimLightDescriptionTemplate("a raised surface upon which two large "
        "objects - perhaps chairs - stand");
    addSomeLightDescriptionTemplate("a huge slab of marble upon which "
        "two thrones stand");
    addDescriptionTemplate("a huge slab of pale blue marbled gilded in gold "
        "upon which two massive amethyst thrones fashioned into stylized "
        "dragon maws stand");

    addItemTemplate("A massive marble slab standing eight inches above the "
        "floor seemingly untouched by age. It is made of a huge slab of pale "
        "blue to gray-red marble with many gold-filled faults. The edges "
        "have all likewise been gilded with gold. Near the middle are two "
        "ornate thrones - each carved from a massive amethyst crystal into "
        "the shape of a dragon's opened maw.");
}
