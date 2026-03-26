//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Fall of Kharand");
    set("short", "A book titled 'The Fall of Kharand'");
    set("title", "The Fall of Kharand: Shadows Over the Vale");
    set("aliases", ({ "fall of kharand", "vale battles", "kharand siege",
        "northern chronicles", "book" }));
    set("long", "This volume chronicles the climactic battles against Kharand, "
        "the courage of knights, dwarves, and villagers, and the rise of "
        "dark powers that challenged the Vale. It records strategy, sacrifice, "
        "and the toll of war, bringing the story of the north to its turning point.");

    addChapter("Chapter 1: Gathering Storm",
        "Reports came of Kharand’s forces gathering beyond the mountains.\n"
        "Beren and Areladur convened the northern lords at Hillgarath.\n"
        "Messengers spoke of thousands of orcs and undead in marching columns.\n"
        "The dwarves of Khazurath prepared siege engines and magical wards.\n"
        "Villagers were conscripted to fortify towns along the Vale’s rivers.\n"
        "Areladur sent scouts into the forests, noting traps and hidden camps.\n"
        "Spies reported strange new commanders among the northern hordes.\n"
        "The air smelled of frost and smoke, as if the land itself warned them.\n"
        "Banners were hoisted, armor polished, and swords sharpened anew.\n"
        "The alliance’s strategy balanced defense with swift counterattacks.\n"
        "Even the bravest felt the weight of the coming storm.\n"
        "Nights were filled with watchfires, and the distant mountains glowed.\n"
        "Rumors spoke of dark magics strengthening Kharand’s dead soldiers.\n"
        "Villagers whispered prayers to old gods and forgotten spirits.\n"
        "Areladur kept a journal, noting fear, hope, and the courage shown.\n"
        "The Vale braced itself, knowing the first blow could decide all.\n"
        "Orders were given to assemble at key passes and river crossings.\n"
        "Scouts returned with reports of bridges burned and roads blocked.\n"
        "The march northward would be perilous, with enemies on all sides.\n"
        "Yet determination held, for the Vale would not bow to shadows.");

    addChapter("Chapter 2: Clash at the Northern Pass",
        "The army reached the narrow northern pass as snow began to fall.\n"
        "Kharand’s forces awaited, a wall of shields and moving dead.\n"
        "Beren led the vanguard, swords gleaming despite the biting wind.\n"
        "Dwarves set traps along the cliffs, axes ready and fire at hand.\n"
        "The first clash was sudden, orcs charging, undead surging without pause.\n"
        "Arrows fell in waves, shields splintered, and the ground shook.\n"
        "Men and dwarves fought side by side, every step hard won.\n"
        "Corpses rose even after being felled, animated by dark sorcery.\n"
        "Areladur’s command kept lines from breaking under relentless assault.\n"
        "Knights formed squares, spears braced, hammers swung, magic unleashed.\n"
        "The battle raged from dawn until the sun dipped behind the mountains.\n"
        "Banners tattered, warriors exhausted, yet the pass held against Kharand.\n"
        "Smoke and blood mixed, leaving trails of horror across the snow.\n"
        "Victory was achieved, but at terrible cost, and the enemy withdrew.\n"
        "Areladur documented every tactic and casualty, the journal heavy with grief.\n"
        "The northern pass remained a barrier, but the war was far from done.\n"
        "Reinforcements were sent, and towns were warned to prepare defenses.\n"
        "The army camped in snow-covered valleys, fires glowing against the dark.\n"
        "Every soldier knew that Kharand would not relent, nor would its necromancy.\n"
        "The clash had ended, but the shadow of war lingered, cold and constant.");

    addChapter("Chapter 3: Secrets Beneath the Mountains",
        "Scouts reported tunnels beneath Kharand’s occupied fortresses.\n"
        "Areladur led a small company to investigate the dark passages.\n"
        "Torches flickered, revealing signs of ritual and ancient carvings.\n"
        "Whispers echoed from stone walls, almost speaking to the living.\n"
        "Dwarves examined runes, their chants countering the enchantments.\n"
        "Strange creatures lurked in the dark, neither dead nor alive.\n"
        "The company moved carefully, every footstep measured and silent.\n"
        "They discovered chambers filled with bones and magical implements.\n"
        "Areladur noted everything, for knowledge was a weapon in itself.\n"
        "Some scrolls hinted at controlling the dead, dark power of Kharand.\n"
        "They returned to the surface, wary of traps and shadowed foes.\n"
        "Reports to Beren and the council informed strategic decisions.\n"
        "The knowledge of the tunnels changed the plans for the coming battle.\n"
        "Every fortification could now be threatened from below.\n"
        "New defenses were constructed, and spies infiltrated the enemy ranks.\n"
        "The alliance learned that war required vigilance in every shadow.\n"
        "The Vale prepared, knowing victory depended on cunning and courage.\n"
        "Even minor victories could sway the course of this deadly campaign.\n"
        "The dark powers of Kharand revealed themselves, subtle and cruel.\n"
        "All understood that patience and resolve were as important as steel.");

    addChapter("Chapter 4: The Siege of Kharand",
        "The alliance reached Kharand’s gates, massive walls looming ahead.\n"
        "Banners flapped in the cold wind, echoing determination of all.\n"
        "Orcish guards and undead patrolled the walls, ever vigilant.\n"
        "Siege engines were placed, ready to batter gates and towers.\n"
        "Arrows and bolts rained from the ramparts, meeting the attackers.\n"
        "Dwarves reinforced the siege with fire, hammers, and counter-magic.\n"
        "Knights charged in waves, attempting breaches under heavy fire.\n"
        "Corpses animated by dark magic struck from hidden positions.\n"
        "Every breach attempt was met with deadly resistance and traps.\n"
        "Beren and Areladur coordinated flanks, supporting faltering sections.\n"
        "The battle stretched for days, neither side yielding ground.\n"
        "Villagers and levies carried supplies, tended the wounded and dead.\n"
        "The siege tested morale, courage, and endurance to their limits.\n"
        "Dark sorcery twisted the battlefield, shadows attacking the mind.\n"
        "Yet determination and unity kept the alliance pressing forward.\n"
        "Plans were adjusted, traps dismantled, weaknesses exploited.\n"
        "Finally, with coordinated assault, a breach was forced in the wall.\n"
        "Banners were planted atop towers, signaling hard-fought triumph.\n"
        "The cost was immense, the blood of heroes staining the streets.\n"
        "Still, the defenders of Kharand had been broken, and hope returned.");
}
