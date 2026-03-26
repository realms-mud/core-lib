//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Last Battle of Mirost");
    set("short", "A grim codex, recounting the fall and fury of Mirost");
    set("title", "The Last Battle of Mirost: Heroes, Shadows, and the Fallen");
    set("aliases", ({ "mirost battle", "final confrontation", "battle of mirost",
        "codex", "book", "grim codex" }));
    set("long", "This codex details the final confrontation at Mirost, where "
        "the Werric Knights, allied dwarves, and the remnants of the city "
        "rose to challenge Argloth, the corrupted, and his undead forces, "
        "commanding Sylthasis' dark power. It contains both historical "
        "accounts and fragments from Argloth's diary, revealing his madness.");

    addChapter("The March to the Ruins",
        "The Werric Knights assembled at dawn, banners heavy with dew.\n"
        "Dwarves of Khazurath and Erebor marched beside them, axes gleaming.\n"
        "From the hills, Mirost's shattered walls loomed, blackened and silent.\n"
        "Argloth had summoned horrors; whispers warned of undead and shadow.\n"
        "Soldiers tightened armor, checked weapons, hearts pounding with fear.\n"
        "A silence fell, broken by the distant roar of Sylthasis.\n"
        "The mountain trembled, and some thought it would swallow all below.\n"
        "Captains shouted final orders; no man or dwarf looked back.\n"
        "From a ruined tower, a tattered scroll fluttered, bearing his hand.\n"
        "\"They will kneel,\" it read. \"Or fall. I am inevitable.\"\n"
        "Knights gripped hilts; dwarves clutched axes. The air was thick with dread.\n"
        "Each step toward Mirost brought memories of earlier losses, burned keeps.\n"
        "Civilians fled to hills; only those hardened by war remained.\n"
        "A scout cried: 'The dead move!' as corpses stirred among the ruins.\n"
        "Argloth's voice rang in the wind: 'All must bend before my command.'\n"
        "Yet courage surged where despair might have ruled.\n"
        "Knights whispered prayers; dwarves muttered old runes.\n"
        "No one laughed. Few spoke. Only the march continued.\n"
        "The mountain awaited, dark and hungry, the final stage set.\n"
        "None knew who would survive the coming storm.");

    addChapter("The Clash Within Mirost",
        "Argloth unleashed the undead dwarves first, their eyes glowing red.\n"
        "Sylthasis circled above, wings blotting the sun, shadow falling on men.\n"
        "Knights struck, steel ringing on corrupted steel, dwarves cleaving undead.\n"
        "The air smelled of smoke, blood, and death; every shout echoed on stone.\n"
        "Amid the chaos, Argloth strode, pale eyes fixed on the living.\n"
        "Fragments of his diary lay on the ground: 'They fear me. They should.'\n"
        "A Werric Knight fell, hand to throat, yet rose again as undead under\n"
        "Argloth. Dwarves hurled axes, severing limbs, yet more rose from\n"
        "shattered walls. Knights formed a wall; dwarves pressed behind,\n"
        "shields and axes interlocking.\n"
        "Every step forward was paid in blood, yet retreat was unthinkable.\n"
        "From a tower, Argloth called: 'I will remake this world in shadow.'\n"
        "Sylthasis descended, teeth bared, a roar shaking stones from the peak.\n"
        "Argloth extended his hand; dead dwarves and corpses moved faster, stronger.\n"
        "Knights shouted their battle cries; dwarves shouted runes, axes raised.\n"
        "Men died. Dwarves died. Yet hope endured in tiny, defiant pockets.\n"
        "A great axe struck Sylthasis' wing; the dragon roared, scattering debris.\n"
        "Argloth screamed, a sound that twisted the air, rattling hearts.\n"
        "His diary page fluttered: 'The mountain speaks. I obey. None can stop me.'\n"
        "A final push of steel and courage closed the distance to the fallen\n"
        "king. The dead trembled. Sylthasis faltered. Mirost quaked with the\n"
        "end's approach.");

    addChapter("The Fall and Aftermath",
        "Argloth fell under combined blows from knights and dwarves.\n"
        "Sylthasis roared one last time, then collapsed, wings shattering on stone.\n"
        "The undead trembled, then crumbled, their shadows dissipating.\n"
        "Victory was won, but the cost was immense: men, dwarves, and knights alike.\n"
        "The mountain was silent. Smoke curled from ruined walls and towers.\n"
        "No one celebrated. Survivors wept for friends, for fallen, for what\n"
        "Mirost was. Fragments of Argloth's diary were gathered, warnings of\n"
        "ambition and power. Dwarves marked the halls, yet refused to dwell\n"
        "there; a taint lingered. Werric Knights swore oaths: Mirost would\n"
        "never rise again, the memory preserved.\n"
        "The mountain seemed to breathe, as if the fallen king still lingered.\n"
        "Yet hope remained; surviving leaders pledged protection and vigilance.\n"
        "They departed slowly, carrying stories, scars, and lessons learned.\n"
        "Mirost would remain a warning: power unchecked breeds ruin.\n"
        "Even in victory, the shadow of madness lingered on the mountain.\n"
        "And Argloth, though dead, would haunt minds for generations.\n"
        "The dwarves whispered: 'Preserve knowledge, not ambition.'\n"
        "The knights whispered prayers, hearts heavy with loss.\n"
        "The mountain, silent once more, watched over the scarred land.\n"
        "All who survived remembered: courage endures, madness destroys. Thus\n"
        "ended the last battle of Mirost, where heroes, shadows, and the\n"
        "fallen met.");
}
