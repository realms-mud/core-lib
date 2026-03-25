//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Blood and Banner");
    set("short", "A book titled 'Blood and Banner'");
    set("title", "Blood and Banner: Campaigns, Sacrifices, and the Price "
        "of Victory");
    set("aliases", ({ "blood and banner", "blood", "banner", "victory "
        "costs", "book" }));
    set("long", "A field report assembled from the journals of captains "
        "and letters home. It details the campaigns leading to the "
        "victories and the price paid in lives, towns, and sleep.");

    addChapter("On the Siege of Orothysse",
        "The siege of Orothysse stretched men to the ragged edge. Trenches "
        "filled with rain and the smell of cold iron. Besiegers and besieged "
        "ate the same bitter stew until supplies ran low. The relief force "
        "that arrived did so at a ruin of smoke and ash. Even when the walls "
        "were saved, the city bore a shadow; a house that stood was only "
        "framed by char and sorrow. The cost was not measured merely in stone "
        "but in the slow decay of a people's trust.");

    addChapter("Of the Fallen King Surachar",
        "Surachar's fall at sea was a turning moment. He inspired more than "
        "fear; his presence bound fleets together. When his galley breached "
        "and he was cut down, Kharandish sailors lost heart and many ships "
        "fled. In the chaos that followed, their centers of command wavered, "
        "allowing allied navies to strike decisive blows and reclaim lost "
        "ports.");

    addChapter("Of the Great Recoveries",
        "Cities retaken require more than blades; they require governors who "
        "can feed the people and keep law while men of arms rebuild walls. "
        "The alliance poured treasure into rebuilding and the scars of war "
        "were made visible in markets and in the slow return of children to "
        "the streets. Each recovered city became a node in a wider network "
        "that needed garrisons, trade, and a sense of security.");

    addChapter("The Aftermath for Hillgarath",
        "Hillgarath gained border security but bled its coffers. Taxes rose "
        "to fund garrisons, and farmers saw sons leave never to return. "
        "Markets tightened and winters were colder in years following the "
        "wars. Yet a hard peace held and in a manner wished for by those who "
        "survived.");

    addChapter("Of the Rebuilding",
        "Workmen and masons came from far and near to rebuild keeps and "
        "harbors. Dwarves refitted forges and ironworkers hammered out new "
        "hinges and portcullises. Women organized relief and set up soup "
        "kitchens where bread and broth were handed out and names of missing "
        "men were read aloud. The rebuilding was not swift, yet it was steady "
        "and shaped by the rhythm of hammers and tears.");

    addChapter("On Memory and Monument",
        "Memorials were raised for the dead: stones carved with names, "
        "mead-halls that rang once a year with the song of those lost. Memory "
        "is an institution as much as a feeling; each name carved needed to be "
        "kept in the books and remembered in the liturgy. Monuments fostered "
        "grief but also bound communities in the work of recollection.");

    addChapter("Letters to Those Left Behind",
        "A selection of letters home shows varied grief: some men wrote of "
        "glory and duty, some confessed fear and shame, many were brief and "
        "practical-requests for socks, bread and the names of friends still "
        "alive. The women's replies kept houses running and the poor fed while "
        "suits of armor gathered dust by empty fires.");

    addChapter("Epilogue: What Victory Bought",
        "Victory bought borders and years of uneasy peace. It bought also "
        "a quiet poverty in many places where the war had taken bread and "
        "dry stone. Victory also purchased a slow, internal cost: men who "
        "returned were not all the same, and the silence at dinner sometimes "
        "had a new, heavy weight. The peace was purchased at the price of "
        "nights of fever and the names of boys that would never be whispered "
        "again.");
}
