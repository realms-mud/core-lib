//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Last Battle of Mirost: Dual Perspectives");
    set("short", "A book titled 'The Battle of Mirost'");
    set("title", "The Last Battle of Mirost: Heroes and the Fallen");
    set("aliases", ({ "mirost battle", "final confrontation", "battle of mirost",
        "the battle of mirost", "book", }));
    set("long", "This codex recounts the final confrontation at Mirost from two "
        "perspectives: the heroic stand of the Werric Knights and allied dwarves, "
        "and the mad descent of Argloth, who commands Sylthasis and the undead. "
        "Diary fragments reveal his growing obsession and corruption.");

    addChapter("The March to Mirost",
        "Knights and dwarves approached Mirost at first light, shields wet with dew.\n"
        "Smoke curled from ruins, blackened stone marking old horrors.\n"
        "Axel of Khazurath tightened his grip on his axe, knuckles white.\n"
        "From the mountain, a low roar echoed; Sylthasis circled above.\n"
        "Corpses in the ruins stirred; the dead would fight for Argloth.\n"
        "A dwarf whispered: 'By stone and forge, we will stand.'\n"
        "Knights shouted prayers; shields rattled on armor, axes gleamed.\n"
        "A wind carried a parchment: Argloth's scrawl, ink bleeding from fear.\n"
        "'They will kneel. Or die.'\n"
        "Kuarl of Erebor read it aloud, voice shaking but steady.\n"
        "The mountain trembled, each step heavy, echoing the doom ahead.\n"
        "No one dared laugh; tension hung thick as smoke.\n"
        "Yet beneath the fear, a spark of defiance burned.\n"
        "Men and dwarves marched forward, towards the tainted halls.\n"
        "A Werric Knight muttered: 'The mountain will test us, but we endure.'\n"
        "Kuarl gritted teeth; even the forge's heat felt mild compared to this fear.\n"
        "Shadows moved unnaturally; the dead obeyed Argloth's voice.\n"
        "The first clash would soon begin, and no one was untouched by dread.\n"
        "All knew the mountain could swallow them whole.");

    addChapter("Argloth Awakens the Dead",
        "From the peak, Argloth's voice carried like a whip across the field.\n"
        "He lifted his staff; undead dwarves staggered from rubble.\n"
        "Kuarl's diary fragment reads: 'I feel them, the old stones tremble with my fury.'\n"
        "Knights charged, steel against corrupted steel, dwarves cleaving through shadows.\n"
        "The air was thick with smoke, blood, and the smell of death.\n"
        "A knight fell, eyes glowing red; undead claimed him instantly.\n"
        "Kuarl: 'I have slain friends, yet they rise again. My hammer feels too weak.'\n"
        "Argloth's laugh rang: 'You cannot resist the mountain's will.'\n"
        "Sylthasis roared overhead, wings blotting the sun, shadow suffocating men.\n"
        "Kuarl: 'The beast mocks me; I swing, I strike, yet the stone beneath shakes.'\n"
        "Knights held line; dwarves threw axes, severing limbs yet more rose.\n"
        "Argloth scrawled in a diary: 'All is becoming clearer. Power is mine to command.'\n"
        "Every step forward was bought with sweat, blood, and tears.\n"
        "Kuarl: 'I pray to Durin, to stone, to anything that hears us.'\n"
        "A knight cried: 'For Mirost!' and surged forward.\n"
        "Sylthasis struck, wingtip smashing stone; dust choked the air.\n"
        "Argloth screamed; even the mountain trembled at his fury.\n"
        "Kuarl's hands shook, yet he swung again, taking down one of the walking dead.\n"
        "The battle was a blur of metal, shadow, and unrelenting terror.");

    addChapter("The Turning of the Mountain",
        "Knights and dwarves pressed into Mirost's shattered inner keep.\n"
        "Corpses fought beside Argloth; undead dwarves clawed and bit.\n"
        "Kuarl: 'I feel my hammer’s weight is nothing; the mountain commands me.'\n"
        "Argloth wrote feverishly: 'The mountain whispers secrets. Sylthasis obeys.'\n"
        "A knight pierced an undead dwarf, only to have it rise again.\n"
        "Kuarl: 'I strike and they rise; yet some spark of life persists.'\n"
        "Sylthasis descended, fire scorching walls, knights diving for cover.\n"
        "Argloth laughed; madness licked every line of his face.\n"
        "Kuarl: 'I have never hated stone and shadow so much.'\n"
        "The Werric Knights formed around Kuarl, axes and swords a wall.\n"
        "Dwarves pressed from the rear, keeping the dead at bay.\n"
        "Kuarl: 'The mountain is alive, and I am nothing.'\n"
        "Argloth: 'Soon the world will kneel. Soon I will be god.'\n"
        "A final surge of men and dwarves smashed through undead ranks.\n"
        "Kuarl: 'I have lost friends, yet the dead cannot hold me forever.'\n"
        "The inner keep loomed; Argloth’s presence dark and consuming.\n"
        "Sylthasis faltered under combined steel; the mountain groaned.\n"
        "Kuarl: 'Perhaps Durin is with us yet.'\n"
        "A single cry, 'For Mirost!' echoed; the tide turned.");

    addChapter("The Fall of Argloth",
        "Argloth fell beneath combined blows; Sylthasis collapsed beside him.\n"
        "Kuarl: 'I do not rejoice. Only relief. The mountain is quiet, yet scarred.'\n"
        "Undead trembled, then disintegrated; shadow lifted from Mirost.\n"
        "Argloth’s diary: 'I am undone… yet I saw truth. The mountain… speaks…'\n"
        "Knights wept for the fallen; dwarves counted their dead silently.\n"
        "Kuarl: 'We will never call this home. Its stones remember evil.'\n"
        "The halls were marked, yet uninhabitable; the taint lingered in stone.\n"
        "Victory was ours, but cost, terror, and madness were etched forever.\n"
        "Kuarl: 'I survived. But how much of me remains unbroken?'\n"
        "The Werric Knights swore oaths; dwarves carved runes for remembrance.\n"
        "Argloth’s diary pages were gathered, warnings of obsession and power.\n"
        "Kuarl: 'Read them and know: noble intent may lead to ruin.'\n"
        "Mirost remained silent; only smoke and shadows spoke of the battle.\n"
        "Heroes departed slowly, carrying stories, scars, and lessons learned.\n"
        "The mountain watched, cold and eternal.\n"
        "Kuarl: 'Courage endures. Madness devours.'\n"
        "The fallen Argloth was a warning, the heroes a memory.\n"
        "All who survived remembered: the mountain does not forgive.\n"
        "Even in victory, the shadow of evil lingered.\n"
        "Thus ended the last battle of Mirost, where both heroism and madness met.");
}
