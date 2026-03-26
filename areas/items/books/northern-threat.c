//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Northern Threat");
    set("short", "A book titled 'The Northern Threat'");
    set("title", "The Northern Threat: Chronicles of the Northern Threat");
    set("aliases", ({ "northern threat", "vale unrest", "kharand threat",
        "northern chronicles", "book" }));
    set("long", "After the Vale was reclaimed, a new threat stirred "
        "beyond the mountains. Kharand's ambitions were not quelled, "
        "and remnants of the undead lingered in secret places. "
        "This volume follows the uneasy peace, the return of spies, "
        "and the heroes who must face dangers both known and unseen.");

    addChapter("Chapter 1: Uneasy Peace",
        "Spring arrived in the Vale, softening the scars of winter.\n"
        "Villagers rebuilt homes, yet fear lingered in quiet corners.\n"
        "Knights patrolled roads, wary of sudden ambushes or mischief.\n"
        "Dwarves inspected gates and towers, chanting old protective songs.\n"
        "Areladur met with Beren atop a hill, surveying the valley below.\n"
        "Fields were sown, but the farmers glanced often toward the woods.\n"
        "Some claimed to see shadows moving where no trees should be.\n"
        "Whispers spread among the townsfolk of dark figures at night.\n"
        "Even children spoke of eerie voices on windless evenings.\n"
        "Areladur called a council, knights, and dwarves gathered in silence.\n"
        "Plans were discussed to patrol further, leaving no path unchecked.\n"
        "Messages were sent to Eledhel, asking for scouts and reinforcements.\n"
        "Beren spoke of spies seen near the passes, returning with tales.\n"
        "Every story hinted at more than simple brigands or orcish bands.\n"
        "Dwarves muttered about old wards weakening, stones losing their power.\n"
        "Areladur noted each report in his journal, attentive to patterns.\n"
        "The peace of the Vale was fragile, held together by vigilance.\n"
        "Each day passed, yet unease deepened with every shadowed forest.\n"
        "The first signs of a rising threat were subtle, almost invisible.\n"
        "Still, the Vale breathed, waiting for the storm to reveal itself.");

    addChapter("Chapter 2: The First Signs",
        "Scouts returned with unusual reports from the northern hills.\n"
        "Tracks appeared that belonged neither to man nor beast.\n"
        "Villagers spoke of cattle found drained of life, eyes open.\n"
        "Areladur gathered his advisors to discuss these omens.\n"
        "The dwarves insisted that magic, dark and old, had awakened.\n"
        "Knights sharpened swords and checked armor, ready for skirmish.\n"
        "Caravans moved cautiously, with armed men flanking each side.\n"
        "A lone rider brought news of distant fires and eerie lights.\n"
        "Beren suggested sending envoys to Eledhel to seek counsel.\n"
        "The council debated whether to strike preemptively or wait.\n"
        "Some feared the enemy was testing the Vale’s resolve carefully.\n"
        "The forests echoed with cries heard only at dusk or dawn.\n"
        "Dwarves reported wards failing on old altars, inscriptions fading.\n"
        "Areladur inspected them personally, touching the stones lightly.\n"
        "Whispers, almost voices, seemed to emanate from the very rock.\n"
        "Even the bravest men felt unease, moving like shadows themselves.\n"
        "The first signs of trouble had arrived, subtle but undeniable.\n"
        "Messages were dispatched to border towns, calling for watchfulness.\n"
        "The northern threat was stirring, patient, hidden, and calculating.\n"
        "And so the Vale braced itself, hoping courage would be enough.");

    addChapter("Chapter 3: Fires in the Pass",
        "Flames rose in a distant pass, orange and black against snow.\n"
        "Scouts raced to report, returning with tales of burning huts.\n"
        "Orcish raiders had crossed, small in number but vicious in attack.\n"
        "Dwarves reinforced the ridge, setting traps and wards.\n"
        "Areladur rode swiftly with a company of knights to intercept.\n"
        "Arrows flew, axes swung, and the clash rang through the mountains.\n"
        "Some corpses moved unnaturally, reanimated by dark magics.\n"
        "Beren led a flank, cutting down foes who rose after falling.\n"
        "The wind carried screams, mixing with the scent of smoke and ash.\n"
        "Dwarves chanted protective incantations, forming a barrier of sound.\n"
        "Knights pressed forward, never allowing the enemy to regroup.\n"
        "The fires were put out, yet whispers of more raiders remained.\n"
        "Areladur took note of odd marks, glyphs scorched into stones.\n"
        "Beren suggested sending spies to learn more about these symbols.\n"
        "The Vale had survived, but it was clear this was only the beginning.\n"
        "Villagers returned cautiously, rebuilding homes while keeping watch.\n"
        "Dwarves repaired towers and gates, strengthening the northern wall.\n"
        "Every night, patrols moved under torchlight, vigilant for ambush.\n"
        "The first battle had been won, but the shadow of Kharand lingered.\n"
        "And the Vale knew the coming days would demand even greater courage.");

    addChapter("Chapter 4: Shadows Gathering",
        "Winter returned, pale and harsh, casting long shadows across hills.\n"
        "Reports of missing travelers caused unease in towns and villages.\n"
        "Knights increased patrols, though the forests seemed to swallow them.\n"
        "Dwarves spoke of unnatural cold where no wind should reach.\n"
        "Areladur convened a council to assess intelligence from scouts.\n"
        "Beren received word from Eledhel: spies had confirmed enemy movements.\n"
        "Villagers whispered of figures moving silently, out of sight.\n"
        "Herders refused to tend flocks beyond the first ridge, fearing attacks.\n"
        "Some knights claimed to have glimpsed spectral shapes among the trees.\n"
        "Dwarves prepared traps, wards, and reinforced watchtowers at every pass.\n"
        "Messages were sent to border towns to maintain constant vigilance.\n"
        "Every day brought new signs that the enemy was clever and patient.\n"
        "The alliance realized that open battle might not suffice alone.\n"
        "Areladur sent scouts further afield to investigate hidden paths.\n"
        "Beren oversaw the training of villagers to defend homes and granaries.\n"
        "The Vale was alive, yet tension hung like frozen mist in the air.\n"
        "Each night, fires were lit to reassure the living and deter the unseen.\n"
        "The shadow of Kharand loomed beyond the mountains, watching and waiting.\n"
        "The people of the Vale would need courage, cunning, and unity.\n"
        "And so the chronicles of vigilance and defiance continued, unbroken.");
}
