//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Founding of Eledhel");
    set("short", "A book titled 'A Song of Ruin and Renewal");
    set("title",
        "The Founding of Eledhel: A Song of Ruin and Renewal");
    set("aliases",
        ({ "eledhel", "song of renewal", "dor-temnost wars", "book", "song" }));
    set("long",
        "A somber codex, its verses weighty with sorrow and resolve. "
        "Here are told the years of famine, tyranny, alliance, and "
        "the rising of a new realm beyond the shadow.");

    addChapter("The Famine and Expansion",
        "In one hundred twenty-one, the queen Aryne fell,\n"
        "And with her passing came a crueler doom.\n"
        "The fields lay barren, rivers ran too thin,\n"
        "And hunger walked where once the harvest stood.\n"
        "Dor-Edhel waned, its people scattered wide,\n"
        "Until its name was taken by the crown.\n"
        "So Dor-Temnost, though pressed by want and grief,\n"
        "Still stretched its hand to gather failing lands.\n"
        "Years passed in ash and slow encroaching fear,\n"
        "Till Ulric rose in Hillgarath as king.\n"
        "Yet in the south, the march did not relent,\n"
        "And many realms were bound beneath one will.\n"
        "Rhundaur fell, and Khendazach was claimed,\n"
        "Each conquest feeding still a greater fire.\n"
        "Then Elonoch was slain upon the field,\n"
        "And Elonoch the second took the crown.\n"
        "He spoke no oath of mercy to his court:\n"
        "'Let fear be law where weakness once held sway.'\n"
        "So began a reign of iron and of pain.\n");

    addChapter("The Burning of Enedloth",
        "In one hundred seventy-seven, unrest rose,\n"
        "And Enedloth cast off the tyrant's yoke.\n"
        "Their banners flew in hope of freedom gained,\n"
        "Their voices rang with cries of liberty.\n"
        "But Elonoch returned with dreadful might,\n"
        "And answered hope with ruin swift and sure.\n"
        "Before the gates, he gave this bitter word:\n"
        "'Let this be known to all who dream of chains\n"
        "Unbroken: I shall break the dreamers first.'\n"
        "The city fell, its people put to sword,\n"
        "No age nor station spared the butcher's hand.\n"
        "Flame took the walls, and silence took the streets,\n"
        "Till none remained to speak the city's name.\n"
        "So fear went forth where once rebellion stirred,\n"
        "And all the lands bent low beneath his gaze.\n"
        "Thus was obedience sealed in blood and ash.\n");

    addChapter("The Child Queen",
        "In one hundred ninety-four, plague struck hard,\n"
        "And Hillgarath was brought to grievous loss.\n"
        "King Ulfred fell, his sons beside him laid,\n"
        "And none remained of that once-mighty line.\n"
        "A child then took the burden of the crown:\n"
        "Ainderie, but six in years and slight.\n"
        "The court stood hushed to see her lifted high,\n"
        "A fragile flame against the gathering dark.\n"
        "Daedrun spoke then before the wavering lords:\n"
        "'I stand as shield until her strength is grown.'\n"
        "So was the realm preserved through careful hand,\n"
        "While time and trial shaped the young queen's will.\n"
        "And none who saw her then could truly guess\n"
        "What strength would dwell within that slender form.\n");

    addChapter("The Queen's Resolve",
        "Years passed, and Ainderie came to her full strength,\n"
        "And took as consort Curudil the wise.\n"
        "Before the court, he spoke and set aside\n"
        "The crown that might have been his by all right:\n"
        "'Not mine the throne, but hers by law and worth;\n"
        "I stand beside, not over, she who rules.'\n"
        "So was their bond made firm in mutual trust.\n"
        "Yet still the shadow lengthened in the east,\n"
        "And whispers grew of Dor-Temnost's designs.\n"
        "Then rose the call for union among realms,\n"
        "And many answered, fearing what might come.\n"
        "Ainderie spoke before the gathered lords:\n"
        "'Alone we fall, but joined we yet may stand.'\n"
        "Thus was the alliance forged in wary hope.\n");

    addChapter("The Unquiet Peace",
        "Along the Lonis rose the forts of war,\n"
        "Each stone a promise that the peace would break.\n"
        "Dor-Temnost watched, and answered in like kind,\n"
        "Till riverbanks were lined with waiting steel.\n"
        "Mirost joined at Ainderie's own call,\n"
        "And Eldarion made ready far and wide.\n"
        "He spoke unto his captains and his kin:\n"
        "'Call forth the north, the mountain, and the vale;\n"
        "For if we stand divided, we are lost.'\n"
        "So came the dwarves, and men of distant lands,\n"
        "And all prepared for war that loomed ahead.\n"
        "Yet when the clash at last was joined in force,\n"
        "Ainderie herself rode forth to lead.\n"
        "'Follow me now!' she cried above the din,\n"
        "'And let no tyrant claim what we defend!'\n"
        "Elonoch fled, his strength undone that day,\n"
        "And thus began a peace that none could trust.\n");

    addChapter("The Waning Years",
        "Long years passed on beneath that fragile peace,\n"
        "Till Elonoch the third assumed the crown.\n"
        "No wisdom marked his hand, nor measured thought,\n"
        "But only hunger for dominion vast.\n"
        "And in the west, the great queen Ainderie,\n"
        "At last laid down the burden of her years.\n"
        "Ninety and more she ruled with steady hand,\n"
        "And left a realm both tempered and made strong.\n"
        "Curudil, grief-stricken, passed beyond the sea,\n"
        "And Eldarendil took the waiting throne.\n"
        "Yet even then the storm began to rise,\n"
        "And all men knew the reckoning drew near.\n");

    addChapter("The Founding of Eledhel",
        "In three hundred eight, the war was loosed anew,\n"
        "And east and west alike were set aflame.\n"
        "Cities fell, yet were reclaimed in turn,\n"
        "As battle surged across the Lonis wide.\n"
        "Bregandil sailed with fire within his heart,\n"
        "And Cuilornir stood fast beside his friend.\n"
        "Before the host, young Bregandil declared:\n"
        "'Here shall we build where none have stood before,\n"
        "A realm unbowed by shadow or by fear!'\n"
        "So in three hundred eleven was it done,\n"
        "And Eledhel was founded in that hour.\n"
        "Men came from west and east to make it strong,\n"
        "A beacon set against the darkened world.\n"
        "And when at last the crown was placed with care,\n"
        "Eldarion spoke before the gathered host:\n"
        "'Not mine this crown, but his who forged this land.'\n"
        "Thus rose a kingdom born of war and will.\n");
}
