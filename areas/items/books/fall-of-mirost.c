//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Fall of Mirost");
    set("short", "A lay of fire and ruin");
    set("title",
        "The Fall of Mirost: A Lay of Fire, Stone, and the Last Defense");
    set("aliases",
        ({ "mirost lay", "fall of mirost", "sylthasis song", "book", "account",
            "lay" }));
    set("long",
        "A heroic lay recounting the destruction of Mirost by the dragon "
        "Sylthasis. Written in the high style, it tells of valor, "
        "defiance, and the ruin that no courage could avert.");

    addChapter("The Coming of Sylthasis",
        "Hear now the fall of Mirost, proud city of stone.\n"
        "Strong were her gates, and high were her towers.\n"
        "Her banners flew bright in the winds of the north.\n"
        "Yet doom came winged from the heights of Utumnadh.\n"
        "Sylthasis the Terrible, flame of the abyss.\n"
        "Fire in her breath, and shadow her mantle.\n"
        "She descended in wrath, and the sky burned red.\n"
        "The people cried out, and the bells rang in terror.\n"
        "No wall could deny her, no watch could foretell.\n"
        "Thus came the dragon, and thus came the end.\n");

    addChapter("The Muster of the Defenders",
        "Then rose the captains, and gathered the host.\n"
        "Steel was made ready, and shields were made fast.\n"
        "They swore by their fathers, by stone, and by crown.\n"
        "'We stand for Mirost, though the world be undone.'\n"
        "Archers took to the walls, and spears filled the gate.\n"
        "The old stood with young; none fled from their duty.\n"
        "The horns of the city rang loud in defiance.\n"
        "And hope, though dim, yet burned in their hearts.\n"
        "For men will stand, though fate has decreed.\n"
        "And honor is held when all else is lost.\n");

    addChapter("The First Fire",
        "Sylthasis descended, her wings blotting sun.\n"
        "Her cry split the heavens, a sound without mercy.\n"
        "Fire fell in torrents, devouring stone.\n"
        "The towers were broken, the gates cast down.\n"
        "Men stood and burned where they would not yield.\n"
        "Arrows were loosed, yet glanced from her hide.\n"
        "Spears were thrown, yet shattered like straw.\n"
        "Still did they fight, though death took them all.\n"
        "For courage does not weigh the cost of the end.\n"
        "It stands, and is broken, and stands yet again.\n");

    addChapter("The Last Stand",
        "Within the breach gathered the last of the guard.\n"
        "Their armor was blackened, their numbers but few.\n"
        "'Hold here,' cried their lord, 'and yield not a step!'\n"
        "'Let fire take flesh, but never our will!'\n"
        "They met the wyrm as it entered the gate.\n"
        "Axes and swords rang loud on her scales.\n"
        "One by one they fell, yet none turned aside.\n"
        "The ground ran with blood, and the air burned with ash.\n"
        "Thus ended the guard, in valor unbroken.\n"
        "Thus stood they to the last, as all songs declare.\n");

    addChapter("The Ruin of Mirost",
        "The city was taken, her people laid low.\n"
        "Flame swept the streets, and silence followed.\n"
        "No voice remained to call out her name.\n"
        "Her halls lay in ruin, her stones cracked and blackened.\n"
        "Sylthasis rose, her wrath unspent.\n"
        "She turned from the ashes, seeking new prey.\n"
        "The survivors fled, scattered and broken.\n"
        "Some to Hillgarath, some to the deep halls below.\n"
        "Mirost was ended, her glory undone.\n"
        "Yet her fall is remembered, while stone yet endures.\n");

    addChapter("The Lament",
        "Weep now for Mirost, and all that was lost.\n"
        "For courage was there, though it could not prevail.\n"
        "Sing of the fallen, whose names are now wind.\n"
        "Recall their defiance, though none could withstand.\n"
        "For such is the doom that comes upon men.\n"
        "Not all battles are won, nor all walls endure.\n"
        "Yet honor remains where brave hearts have stood.\n"
        "And memory endures when cities have fallen.\n"
        "So is the tale told, and so shall it be.\n"
        "The fall of Mirost, in fire and in song.\n");
}
