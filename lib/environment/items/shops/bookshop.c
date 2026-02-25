//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bookshop interior");

    addItemTemplate(
        "The bookshop is a cramped, inviting space that smells of old paper "
        "and binding glue. Tall shelves stretch to the ceiling, packed with "
        "leather-bound volumes, loose manuscripts, and rolled scrolls tied "
        "with colored ribbon. A reading desk near the window holds an open "
        "atlas and an inkwell with several quill pens. Stacks of unsorted "
        "books occupy every spare surface, and a rolling ladder provides "
        "access to the highest shelves. A cat dozes on a cushion atop a "
        "particularly stable pile of tomes."
    );

    addNearDarkDescriptionTemplate(
        "the bookshop is lost in darkness, the towering shelves of books "
        "forming an oppressive maze of shadows"
    );
    addLowLightDescriptionTemplate(
        "the bookshop shelves are dim walls of indistinct spines, the "
        "titles unreadable in the poor light"
    );
    addDimLightDescriptionTemplate(
        "enough light filters in to reveal the packed bookshelves and the "
        "reading desk by the window, though titles remain hard to read"
    );
    addSomeLightDescriptionTemplate(
        "the bookshop is well-lit enough to browse the shelves and read "
        "the gilt titles stamped on the leather spines"
    );
    addDescriptionTemplate(
        "light pours through the window, illuminating the rich colors of "
        "the book spines and the dust motes drifting lazily through the air"
    );
}
