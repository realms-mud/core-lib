//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("echo pool");
    suppressEntryMessage();

    addDescriptionTemplate("in the center of the chamber, a shimmering "
        "pool of purple liquid pulses with an inner light. As you "
        "gaze into its depths, ghostly images swirl and fragment - "
        "echoes of a life lived long ago. Six scenes replay in "
        "jumbled disorder. Each is labeled with a letter. They seem "
        "to tell a story, if only you could determine the correct "
        "order.\n\n"
        "##call_other::key::/tutorial/temple/objects/echo-pool.c::displayEchoes::"
        "\nUse 'order <letter> <position>' to arrange them (1-6). "
        "Use 'clear echoes' to reset. Use 'vision <letter>' to "
        "examine a fragment more closely");
    addSourceOfLight(10);

    addAlias("pool");
    addAlias("echoes");
    addAlias("shimmering pool");
    addAlias("echo pool");

    addItemTemplate("the pool shimmers with an inner light. Ghostly "
        "images swirl beneath its surface - six fragmented echoes "
        "of memory, each labeled with a letter. They seem to tell "
        "a story, if only you could arrange them in the correct "
        "chronological order");
}
