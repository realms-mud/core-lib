//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The End of Shadows");
    set("short", "A book titled 'The End of Shadows'");
    set("title", "The End of Shadows: Triumph in the Vale");
    set("aliases", ({ "end of shadows", "kharand finale", "vale triumph",
        "northern chronicles", "book" }));
    set("long", "This volume recounts the final struggles against Kharand, "
        "the purging of the undead, and the restoration of the Vale. "
        "It follows the leaders, knights, dwarves, and villagers who "
        "faced overwhelming darkness and emerged victorious, though "
        "scarred. The story concludes the northern chronicles, tying "
        "together sacrifice, strategy, and the resilience of life.");

    addChapter("Chapter 1: Rallying the Vale",
        "Beren and Areladur rode through Hillgarath, summoning forces.\n"
        "Villages sent men and supplies, children waving banners high.\n"
        "Dwarves forged weapons and armor, sharpening blades of every kind.\n"
        "Scouts returned with news of weakened Kharand patrols.\n"
        "Allies convened councils to divide tasks and plan final strikes.\n"
        "Every soldier understood the cost: death and shadow awaited.\n"
        "Magic-users reinforced wards and blessings across the Vale.\n"
        "The northern passes were fortified, traps laid for the enemy.\n"
        "Villagers were trained to support the army and tend the wounded.\n"
        "Beren addressed the troops, voice carrying hope and resolve.\n"
        "Areladur reminded the dwarves of Khazurath's ancient valor.\n"
        "Orders were given for simultaneous strikes to prevent retreat.\n"
        "The alliance marched with measured steps, eyes on Kharand.\n"
        "Snow covered the fields, footprints marking the determined advance.\n"
        "Even the winds seemed to hold their breath, watching the march.\n"
        "Every banner, every drumbeat, carried the promise of retribution.\n"
        "Spies reported shadows fleeing at the army's approach.\n"
        "The stage was set for the final confrontation of the Vale.\n"
        "No man, dwarf, or mage doubted that victory required unity.\n"
        "Hope and fear moved together, entwined as the forces marched.");

    addChapter("Chapter 2: Breaking the Northern Wall",
        "The army reached Kharand's northern wall as dawn painted frost.\n"
        "Siege engines thundered, stones crashing, gates shuddering under force.\n"
        "Knights charged with horns blaring, shields interlocked in steel.\n"
        "Dwarves hurled axes, hammers, and fire, breaking enemy ranks.\n"
        "Dark wraiths emerged from towers, attacking with unnatural speed.\n"
        "Magic-users countered with light and wards, shields of radiant power.\n"
        "Corpses rose again, but the alliance fought with steady resolve.\n"
        "Areladur led a detachment through a secret passage discovered before.\n"
        "They struck from behind, cutting off reinforcements, sowing confusion.\n"
        "Beren rallied the main army, turning Kharand's walls into a killing ground.\n"
        "The northern wall fell by midday, gates breached and banners planted.\n"
        "Every soldier, exhausted, knew the tide had finally turned.\n"
        "The enemy retreated into inner keeps, shadows clustering in the corners.\n"
        "Reports of dark commanders falling reached the allied generals quickly.\n"
        "Morale surged; yet caution remained, for Kharand's heart was still strong.\n"
        "Villagers cheered, but swords never left the hands of the weary.\n"
        "Every advance was measured, every flank guarded against counterattack.\n"
        "The first step of the final assault had been taken and held.\n"
        "The northern wall's stones were slick with blood and melting frost.\n"
        "Victory was near, but the shadow still awaited in the keep.");

    addChapter("Chapter 3: The Heart of Darkness",
        "The allied forces entered Kharand's central keep as dusk fell.\n"
        "Shadows thickened, twisting in impossible shapes across stone halls.\n"
        "Undead rose from every corner, commanded by dark sorcery.\n"
        "Beren and Areladur pressed forward, cutting through the tide of death.\n"
        "Dwarves smashed gates with axes, opening new paths for soldiers.\n"
        "Spells of light clashed with necromantic energy in eerie flashes.\n"
        "The commanders of Kharand appeared, cloaked in blackened steel.\n"
        "Every blow exchanged was heavy, filled with fear and desperation.\n"
        "Areladur struck down one, Beren another, until the leaders fell.\n"
        "The undead faltered as their masters were destroyed, losing control.\n"
        "Villagers and levies followed cautiously, cleaning hallways and rooms.\n"
        "The keep shook with the dying energies of Kharand's dark magics.\n"
        "Ancient wards collapsed, allowing light to pierce the shadows.\n"
        "The army pressed to the throne room where the final sorcerer stood.\n"
        "He unleashed all remaining power, summoning storms of shadow and bone.\n"
        "Beren raised his sword, Areladur chanted an ancient binding spell.\n"
        "The clash of light and darkness filled the hall with thunderous force.\n"
        "At last, the sorcerer fell, the shadows dissipating like mist at sunrise.\n"
        "Silence followed, broken only by the exhausted sighs of the victors.\n"
        "Kharand's heart had been purged, the Vale free from its grasp.");

    addChapter("Chapter 4: The Vale Restored",
        "Morning light filled the streets of the reclaimed towns and villages.\n"
        "The dead were laid to rest, altars and shrines restored where possible.\n"
        "Beren and Areladur toured every district, offering aid and reassurance.\n"
        "Dwarves repaired fortifications, mending walls, gates, and towers.\n"
        "Villagers returned to fields, sowing crops and rebuilding homes.\n"
        "Messages were sent to distant allies, reporting the fall of Kharand.\n"
        "Peace councils convened, distributing lands and duties among lords.\n"
        "Festivals celebrated survival, valor, and the end of shadows.\n"
        "The horrors of war left scars, yet the Vale's people stood renewed.\n"
        "Beren decreed that the chronicles of these events be recorded.\n"
        "Areladur oversaw the establishment of watchtowers to guard the passes.\n"
        "Dwarves were honored for bravery, sacrifices remembered for generations.\n"
        "Magic-users sealed wards, ensuring no return of Kharand's dark power.\n"
        "Villagers offered prayers for those who had fallen defending the land.\n"
        "The Vale prospered once more, united by trials and the bond of survival.\n"
        "Banners waved in gentle winds, symbols of freedom and vigilance.\n"
        "Songs were sung of courage, strategy, and hearts that did not falter.\n"
        "The northern mountains returned to silence, their secrets buried.\n"
        "History would remember this time, the triumph of light over shadow.\n"
        "And the Vale endured, tempered by fire, blood, and the strength of unity.");
}
