//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("meat hook");
    addAlias("hook");
    addAlias("hanging hook");
    addAlias("iron hook");

    addAdjectives(({ "iron", "sharp", "rust-spotted", "heavy",
        "cruel-looking", "curved", "dangling", "chain-hung", "stained",
        "well-used" }));

    addDescriptionTemplate("a ##Adjective## meat hook dangling from the ceiling");

    addItemTemplate(
        "The meat hook is a heavy curved piece of iron hanging from a "
        "chain bolted to a ceiling beam. Its point is sharp and slightly "
        "rust-spotted, and dark stains discolor the metal. Several hooks "
        "hang in a row, some empty, others bearing wrapped haunches or "
        "strings of sausages."
    );

    addSomeLightDescriptionTemplate(
        "iron meat hooks dangle from the ceiling, some bearing hung meats"
    );
    addDimLightDescriptionTemplate(
        "dark shapes dangle from the ceiling on chains and hooks"
    );
    addLowLightDescriptionTemplate(
        "things hang from the ceiling, swaying slightly"
    );
    addNearDarkDescriptionTemplate(
        "chains clink softly overhead and something hangs from the ceiling"
    );
}
