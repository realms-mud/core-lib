//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Rising Shadow II: Kharand and the Lonis Vale");
    set("short", "A book titled 'The Rising Shadow, Vol II'");
    set("title", "The Rising Shadow: Kharand and the Lonis Vale");
    set("aliases", ({ "rising shadow", "lonis chronicle", "kharand wars",
        "book", "the rising shadow", "volume 2", "vol 2", "volume ii" }));
    set("long", "This work recounts the years of upheaval following the "
        "fall of Mirost, the rise of Kharand under Zarnedh, and the "
        "struggles of Hillgarath and Eledhel to preserve their realms. "
        "It blends formal record, personal witness, and speeches of leaders.");

    addChapter("Chapter 7: Shadows at the Gates",
        "The walls of Kharand loomed high, black against the pale snow.\n"
        "Scouts returned with grim news: the gates were guarded not just by men.\n"
        "Figures moved behind the battlements, unnaturally silent.\n"
        "Areladur studied the walls through his spyglass, noting every shadow.\n"
        "Beren circled the camp, speaking quietly to captains and dwarves.\n"
        "The night air smelled of smoke and iron, a warning unheeded.\n"
        "Men whispered of horrors seen, but none could confirm the tales.\n"
        "Some claimed to see glowing eyes in the towers, following their movements.\n"
        "Dwarves tested the ground near the gates, finding wards broken.\n"
        "The alliance gathered, swords and axes polished, spells whispered anew.\n"
        "Fires were kept low, lest the enemy see and strike before dawn.\n"
        "Every soldier kept watch, eyes straining for movement in the dark.\n"
        "The snow fell thick, muffling sound and masking footprints.\n"
        "Areladur recorded each observation in his journal, careful and methodical.\n"
        "Some knights laughed nervously, the sound sharp in the quiet night.\n"
        "The tension grew with every hour, a weight that pressed on shoulders.\n"
        "The mountains above seemed to hold their breath, watching.\n"
        "At midnight, the first signs of life stirred atop the walls.\n"
        "Figures moved like shadows, yet they were no ordinary guards.\n"
        "The siege of Kharand had begun before the battle truly started.");

    addChapter("Chapter 8: The First Blood",
        "Dawn broke with fire and horn, and the allies surged forward.\n"
        "Banners snapped in the wind as the first clash rang out.\n"
        "Orcish archers loosed volleys, and men fell into snow and mud.\n"
        "Dwarves smashed the gates with axes, splinters flying into the sky.\n"
        "Areladur shouted orders, his voice cutting through smoke and chaos.\n"
        "Knights rode into the fray, lances and swords gleaming.\n"
        "The enemy's lines wavered, but hidden horrors lurked behind them.\n"
        "Some men vanished, taken by shadows that moved faster than thought.\n"
        "The air smelled of fire, iron, and a bitter, unnatural scent.\n"
        "Areladur fought near the walls, seeing both bravery and terror.\n"
        "Dwarves held their ground, axes swinging, shouting in defiance.\n"
        "Beren led a charge through a breach, cutting down all who opposed.\n"
        "Cries of men and orcs echoed, mingling with strange whispers.\n"
        "The ground was slick with blood and snow, a treacherous path.\n"
        "Knights swore oaths to fallen comrades even as they fought.\n"
        "Some dared laughter, grim and hollow, at the absurdity of war.\n"
        "The siege raged from dawn into afternoon, relentless and cruel.\n"
        "Areladur noted each loss in his journal, his hand steady despite fear.\n"
        "The walls began to crumble, the gates splintered and torn.\n"
        "The first blood had been spilled, but the fight was far from over.");

    addChapter("Chapter 9: The Dark Sorcerer",
        "Beyond the walls, a figure watched, cloaked in shadow.\n"
        "Zarnedh the Great had called forth powers older than any living memory.\n"
        "Spells flickered through the air, lightning snapping across stone.\n"
        "Men fell unconscious, their minds twisted by visions of fire and death.\n"
        "Dwarves muttered incantations, trying to shield themselves from the magic.\n"
        "Areladur's sword cut through an orc, yet his mind feared the unseen.\n"
        "Beren struck down one of Zarnedh's lieutenants, the clash ringing like\n"
        "steel. The shadows seemed alive, moving of their own will, swallowing men.\n"
        "Fires from the walls danced like spirits, illuminating terror in the snow.\n"
        "Areladur rallied his knights, calling for courage against the darkness.\n"
        "Some envoys fainted, unable to endure the unnatural visions.\n"
        "Dwarves pressed forward, axes biting into stone and flesh alike.\n"
        "The air vibrated with magic, thick and suffocating.\n"
        "Zarnedh appeared atop a tower, robes flowing, eyes glowing.\n"
        "He summoned horrors from shadows, creatures men could barely name.\n"
        "Areladur raised his shield, praying that courage might be enough.\n"
        "The knights of Hillgarath and Eledhel formed lines, unyielding.\n"
        "Dwarves carved wards into the snow, anchoring spells to the earth.\n"
        "The battle had become a war of flesh and arcane, and few could tell\n"
        "which would prevail. Yet none faltered; hope burned despite the\n"
        "darkness around them.");

    addChapter("Chapter 10: The Heart of Kharand",
        "The allies breached the inner courtyard, smoke and ash thick around them.\n"
        "Zarnedh summoned more creatures, shadows crawling from walls and floors.\n"
        "Men screamed, dwarves roared, and the clash of steel filled the night.\n"
        "Areladur fought toward the tower, seeking the sorcerer himself.\n"
        "Beren cleared a path, slaying orcs and twisted beasts alike.\n"
        "The courtyard became a storm of blood, snow, and magic.\n"
        "Some knights fell, their bodies swallowed by shadows before they hit\n"
        "the ground. Dwarves pushed onward, axes biting, shields splintering\n"
        "but unyielding. Areladur saw Zarnedh atop the tower, staff raised,\n"
        "power radiating.\n"
        "Lightning cracked the stones around them, arcane fire searing flesh.\n"
        "The allied leaders called for a final charge, voices trembling but resolute.\n"
        "Men and dwarves surged together, banners snapping through the smoke.\n"
        "Zarnedh laughed, a sound that chilled the blood and bent minds.\n"
        "Spells struck allies, some felled instantly, yet others pressed forward.\n"
        "Areladur drew every ounce of strength, running, leaping, striking.\n"
        "Beren and the dwarves followed, forming a living shield of courage.\n"
        "The courtyard was a storm of chaos, yet a path opened to the tower stairs.\n"
        "Shadows recoiled as the first strike reached the sorcerer's feet.\n"
        "The tide of battle shifted, slowly, inexorably, toward the allies.\n"
        "Hope burned, faint but real, amidst the ruins of Kharand.");

    addChapter("Chapter 11: The Fall of Zarnedh",
        "Areladur reached the tower, staff of the sorcerer glowing with malice.\n"
        "Beren smashed the doors, cutting down guards and twisted creatures.\n"
        "The dwarves pressed from behind, axes swinging, shields raised.\n"
        "Zarnedh's eyes blazed, lightning striking the walls and floor.\n"
        "The air itself seemed alive, trying to push them back, yet they pressed on.\n"
        "Areladur leapt, sword striking through magical barriers.\n"
        "The sorcerer staggered, chanting curses that shook the stones.\n"
        "Beren joined, their combined strength hammering the magic apart.\n"
        "Dwarves cut down summoned horrors, each blow ringing in frozen silence.\n"
        "Zarnedh fell backward, staff clattering across the stones.\n"
        "The shadows collapsed, fleeing the light and courage before them.\n"
        "Areladur's sword found the sorcerer's chest, silence answering the cry.\n"
        "Beren and the dwarves cheered, though their voices trembled with exhaustion.\n"
        "The courtyard lay in ruins, but the allies had prevailed.\n"
        "Snow fell on broken banners, blood, and shattered stone.\n"
        "Men helped wounded men, dwarves tended their own, and the dead were counted.\n"
        "Victory was theirs, but the cost was heavy and deep.\n"
        "Areladur recorded it all in his journal, knowing memory would be\n"
        "their only shield. The dark power of Kharand was broken, yet\n"
        "whispers of shadows remained. They looked toward home, knowing the\n"
        "Vale would never forget this night.");

    addChapter("Chapter 12: After the Winter",
        "The snow melted, revealing fields and roads scarred by battle.\n"
        "Villages slowly recovered, though many remained abandoned.\n"
        "Men and dwarves rebuilt gates, reforged armor, and tended to wounds.\n"
        "Areladur and Beren rode through towns, offering hope and guidance.\n"
        "Stories spread of the fall of Zarnedh and the courage of the alliance.\n"
        "Dwarves spoke quietly of wards renewed, of magic cleansed by fire and steel.\n"
        "The mountains no longer seemed alive, yet the memory of shadows lingered.\n"
        "Children played near rivers, though eyes were cautious and wary.\n"
        "Knights patrolled, keeping peace, though hearts remained heavy.\n"
        "Areladur continued his journal, chronicling the winter of war and shadow.\n"
        "He noted bravery, loss, magic, and whispers of powers beyond reckoning.\n"
        "Beren swore that Hillgarath would never forget the courage displayed.\n"
        "Villages repaired their homes, rebuilding what had been lost.\n"
        "The Vale slowly returned to life, yet silence sometimes carried memory.\n"
        "Dwarves returned to their halls, the scars of Mirost and Kharand\n"
        "carried in mind. Allies spoke of unity and vigilance, knowing\n"
        "darkness could return. Snow fell again, lighter this time, as though\n"
        "forgiving the blood spilled. Areladur looked to the mountains,\n"
        "recording every lesson learned. The Vale endured, stronger but wary,\n"
        "shaped forever by the Winter of Shadows. Thus ended the war against\n"
        "Kharand, yet its memory would linger like a shadow on stone.");
}
