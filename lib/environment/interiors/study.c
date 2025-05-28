//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("study");

    addAdjectives(({
        "scholarly chamber with shelves of leather-bound tomes and scrolls",
        "quiet retreat where an ornate desk sits beneath a stained-glass window",
        "study where candles flicker beside inkwells and quill pens",
        "book-lined room where maps and charts cover much of the wooden walls",
        "learned sanctuary with astronomical instruments on polished tables",
        "private chamber with a reading lectern and comfortable cushioned chair",
        "warm study where a modest hearth keeps the chill from precious manuscripts",
        "room where specimens of flora and fauna line labeled shelves",
        "contemplative space where globes and measuring devices await scholarly hands",
        "study adorned with family crests and ancestral portraits",
        "modest chamber where the scent of parchment and ink permeates the air",
        "well-appointed room with tapestries depicting scenes of ancient lore",
        "secluded study where alchemical apparatus shares space with theology texts",
        "thoughtful retreat where candle wax has dripped onto aged wooden surfaces",
        "meticulous chamber where every book and scroll has its designated place",
        "scholarly haven where a large writing desk dominates the center",
        "quiet room where time seems measured only by the burning of candles",
        "personal sanctuary where letters and documents await sealing wax",
        "dignified study where leather chairs invite long hours of reading",
        "learned chamber where the tools of knowledge await their master's hand"
    }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy study where only the faint outlines of bookshelves and furniture "
        "are visible. The smell of parchment, ink, and leather bindings lingers in "
        "the darkness, hinting at the scholarly purpose of this room"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit study where the shapes of a writing desk, bookshelves, and "
        "reading chairs emerge from the shadows. The occasional glint of metal "
        "might be from instruments of astronomy, geography, or other scholarly pursuits"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where just enough illumination filters through "
        "to reveal worn leather book spines, scrolls tied with ribbon, and the "
        "polished wood of furniture dedicated to the pursuit of knowledge"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. The illumination, whether from windows or "
        "multiple candles, reveals the full nature of this space dedicated to "
        "learning and reflection. Every detail, from the carefully arranged books "
        "to the instruments of scholarship, speaks of a mind devoted to knowledge"
    );
}
