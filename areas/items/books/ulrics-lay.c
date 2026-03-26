//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Ulric's Lay: The King's March");
    set("short", "A broadleaf-bound epic of a fallen king");
    set("title", "Ulric's Lay: The King's March and the Mhordrath"
        " Advance");
    set("aliases", ({ "ulric's lay", "ulric", "king ulric", "lay",
        "epic", "book" }));
    set("long", "A broadleaf-bound epic, stitched with iron thread. The "
        "poem within is composed in the old heroic strain, replete "
        "with refrain and shield-song. It tells of King Ulric's deeds "
        "during the Mhordrath Advance and his last stand in Year 31.");

    addChapter("I - The Horn at Dawn",
        "When dawn unrolled its linen light o'er Hillgarath's wall, the "
        "horn of Ulric sounded thrice. Banners shook like thunder across "
        "the vales; the men who slept in the keep rose at the call. Old "
        "veterans rubbed sleeps from their eyes and young lads stiffened "
        "at the smell of oil and saddle. Spears were taken from racks, "
        "shields oiled, and helms strapped hard. Ulric's voice went up "
        "above the clatter and the horses' snorts: 'Rise, sons of the "
        "king, gird your loins and hold the Gap of Delerath.' The words "
        "rolled like a drumbeat and filled the valley; mothers pressed "
        "children close and men kissed love tokens in silence before they "
        "went. At the horn's third note the city gates yawed wide, and the "
        "east road was set with marching men whose shadows lengthened "
        "toward the sun.");

    addChapter("II - The King's Oath",
        "Ulric took an oath by hearth and sword, by the memory of his sire "
        "and by the long line of guardians who had carved the keep from "
        "stone. He bound himself to stand when others fled, to hold the "
        "line against the Mhordrath's swelling tide, and to shield the "
        "weak at his own cost. He spoke these vows in the hall where the "
        "tapestries still bore the stain of earlier wars and where old "
        "captains leaned upon polished staves and heard his voice. A "
        "smith brought forth a ring of iron and Ulric slipped it upon his "
        "finger as a token; the captains kissed the flat of his hand and "
        "swore their lives. This was no parade oath but a bond writ in the "
        "marrow: it would govern judgment and fate until the last trumpet "
        "sounded for him.");

    addChapter("III - The March to Delerath",
        "They marched through alder and ridge, through morning mist that "
        "smelled of river peat and smoke from distant farmsteads. Columns "
        "of spears and shields moved like the ribs of some great beast "
        "across the fields. Ulric's stride was steady, a measured pace for "
        "men and beasts alike; he listened to reports from scouts, nodded "
        "at the sight of smoke on the skyline, and saw to the wounded with "
        "a quiet hand. The marchers sang old camp songs between steps to "
        "keep dread from growing teeth; the minstrels beat time with drum "
        "and told of past victories and of fathers who had fallen. The road "
        "bent toward Delerath, where a narrow gap would decide the passage "
        "for many generations to come.");

    addChapter("IV - The First Clash",
        "On the third day the Mhordrath came, a grey tide of horn and chain. "
        "The vanguard stumbled into skirmishers who shot like wasps from "
        "behind hedges. Ulric rode into the line with a calm that steadied "
        "the men, his face set like flint. Spears locked as men met, and the "
        "air filled with the clatter of iron on iron. The king's shout cut "
        "the chaos and the captains moved to hold the line; the enemy "
        "pressed and then faltered where the banner passed. It was not a "
        "rout, but a warning-first blood for both sides-and the keepers of "
        "Hillgarath learned then the mettle of their foe.");

    addChapter("V - The Shieldwall Holds",
        "Ulric's captains set the wall: iron shoulders knit as one, shields "
        "interlaced, with spears bristling outward like a hedgehog's quills. "
        "He stood amid the ranks as if rooted to the earth, his voice an "
        "anchor for wavering men. Arrows struck like rain, and the shield "
        "rims rang until lips were cut. Yet the formation did not yield; "
        "each man was a link in a chain welded by oath. In that slow, "
        "grinding hour the enemy's momentum ebbed, then broke upon the "
        "steel teeth of the Werric bulwark. When the clouds parted, the "
        "sun gilded the faces of those who had stood and left pools of "
        "shadow where the fallen lay.");

    addChapter("VI - The Grey Banner of Kharand",
        "A rider bore a grey banner on the field and thought the king was "
        "old and soft. He would learn otherwise. Ulric turned his horse, "
        "met the rider in a rash clash, and their blades sang. The banner-"
        "man's horse stumbled and he fell into the mud; Ulric's hand "
        "crushed the life from him as if twisting a knot. The grey banner "
        "sagged and was trampled beneath the boots of the king's men. The "
        "sight of that fallen standard quickened the blood of the Hillgarathi, "
        "who raised a cheer that echoed down the valley and stiffened the "
        "backs of wavering comrades.");

    addChapter("VII - The Smith's Blessing",
        "At dusk the campfires flared and the smiths brought Ulric a new "
        "helm, tempered through night and blessed by the hammer. The metal "
        "smelled of coal and sweat; the smith's hands trembled as he fit it. "
        "Ulric placed the helm upon his brow and blessed the smiths in return "
        "with coin and kind words. That night men slept nearer the forge, "
        "comforted by the ring of hammer and by the knowledge that their king "
        "would wear armor bearing the marks of home. He named the smiths to "
        "small honors and the songs of their work traveled among the tents.");

    addChapter("VIII - The Fevered Watch",
        "A fever ran through the ranks like a stray ghost; it took stout men "
        "and lighted none of them for long. Ulric walked among the tents with "
        "water and cloth, speaking softly to sweating soldiers. He did more "
        "than issue orders; he tied bandages, broke stale bread, and listened "
        "as men murmured of wives. His presence was a balm; shared bread "
        "eased fear and steady hands of healers bound wounds. By dawn the "
        "fever had abated in many, for the king had told the story of his own "
        "childhood and a jest that twisted dread into a smile.");

    addChapter("IX - The Counsel at the Ford",
        "At the Lonis ford the captains took counsel under a wind that "
        "smelled of wet stone. The Mhordrath grew in number like a storm "
        "cloud, pressing at many points. Ulric measured the ford with an "
        "eye like a cartographer's; he marked where to set palisades and "
        "where to post archers. 'Here we stay and here we bind our fate,' he "
        "said, and the men swore the oath again. Engineers dug and filled, "
        "and the ford became a trap -- a narrow throat that would choke a "
        "host.");

    addChapter("X - The Archer's Rage",
        "Skirmishers and archers of the Mhordrath raked the plain with "
        "black-flight; their shafts drove like a wind of needles. Ulric led "
        "a sally of horse and bow, a ragged crown of lances that struck like "
        "iron hail. He called out the names of wounded men as he passed, "
        "spurring on comrades to rescue those who fell. The enemy archers, "
        "taken aback by the sudden charge, lost cohesion; many horses "
        "panicked and threw riders, and for a time the field lay between two "
        "breaths of silence, both sides tasting the blood of victory and "
        "loss.");

    addChapter("XI - The Maiden of Delerath",
        "A maiden at the keep cast herbs and bound threads for the king's "
        "safe keeping. Ulric stopped and took her scarf as talisman, pressing "
        "it beneath his breastplate. She wished blessings upon his house and "
        "wept as his men passed. Later, when the shells of battle lay about "
        "like spent stars, the king would unroll that scarf and find among "
        "its threads the scent of home. He kept it as a second heart and gave "
        "the maiden a small purse and a promise that her village would be "
        "sheltered.");

    addChapter("XII - The Night of Wolves",
        "Under the hush of moon, wolves crept close to camp, drawn by the "
        "sick and the warmth of bones. Ulric set traps and lit patrol fires, "
        "riding the lines with lantern and spear. His lanterns cut the dark "
        "like beacons, and the wolves slunk away to find easier prey. He "
        "watched men sleep and listened to the creak of harness; no wolf took "
        "the standard while his breath was warm in the air, and the next "
        "morning men joked of the king's superstition.");

    addChapter("XIII - The Tale of Three Captains",
        "Three captains arrived with quarrels bent like old rope. They blamed "
        "each other for a lost convoy and would cut each other's throats for "
        "honor. Ulric called them before the fire, named their fathers and "
        "reminded them of shared blood and shared fields. He spoke of sowing "
        "and harvest, of sons who would never learn a trade if the captains "
        "split amongst themselves. The quarrel unwound like old rope; under "
        "his hand they made a knot anew and swore to hold the road in common "
        "rather than tear it to pieces.");

    addChapter("XIV - The Rain of Iron",
        "A rain of iron came as the Mhordrath hurled axes and javelins like "
        "hail. Shields sang and men bent like saplings, but Ulric went "
        "foremost, cutting and calling. The line bent and then straightened "
        "under him, and where he bore, a path opened as if cut by a saw. Many "
        "fell; many faces were bloodied, and yet the men stood. The smiths in "
        "the rear worked without sleep, repointing spears and tempering "
        "broken blades anew, their hands a blur beneath the sparks.");

    addChapter("XV - The Banner's Fall and Rise",
        "Once the king's banner was pierced and fell into the mud, a young "
        "page climbed and took it, blood on his small hand. Ulric lifted him "
        "up, set the standard into the boy's grasp, and placed his own helm "
        "upon the child's head as a jest to steel his courage. The sight of "
        "the page with banner renewed the hearts of the men, and they pressed "
        "on as if they were all young and unstoppable. The boy's cry became "
        "a drum that drove the enemy back for a brief and furious hour.");

    addChapter("XVI - The Song at Noon",
        "At noon they broke bread and sang to still the nerves of men. The "
        "minstrel's lute changed the taste of stale rations to that of "
        "festival bread; laughter and song knit wounds of the spirit. Ulric "
        "listened and paid the minstrel with a ring and a nod, both small "
        "things that carry weight in a field where sorrow is a constant "
        "shadow. The men ate and remembered why they fought: for hearth and "
        "kin.");

    addChapter("XVII - The Betrayer's Shadow",
        "A whisper from within the walls carried to the enemy like a candle "
        "flame. A traitor sought coin or favor, but the king learned and took "
        "measures. Ulric set doubled watches, punished those who would sell "
        "truth, and used counter-weights of rumor to unmask the speaker. "
        "Trust, once cracked, must be carved anew; he did so with prudence and "
        "stern hand, and the shadow of betrayal shrank back like a thing "
        "burned by sun.");

    addChapter("XVIII - The Last Great Charge",
        "When the Mhordrath massed for a final hammer, Ulric mounted his "
        "spear and rode with all captains at his side. The charge broke like "
        "a wave against stone; men crashed and shields splintered, banners "
        "like torn sails. Ulric's voice rose and fell, calling names and "
        "sounding the beat of steel. The enemy staggered and retreated where "
        "the ground had been cleared by the king's blade. For an hour the "
        "valley echoed with the clamor of victory and the moans of the "
        "dying.");

    addChapter("XIX - The Wounds that Do Not Close",
        "Ulric took wounds that marked him. An arrow's braid pierced "
        "shoulder, a blade bit his thigh; the pain came and went like a "
        "tide. He smoked like a forge but would not yield, saying softly, "
        "'Pain is the coin of honor.' He sat with healers and learned names "
        "of poultices; he blessed their hands and gave coin to their jars. "
        "Yet the wound grew into a scar that would remind him of the day "
        "his body had paid part of the price.");

    addChapter("XX - The Farewell to Sons",
        "He wrote letters to those who would wear his name, to sons and "
        "kinsmen, threading careful counsel into ink. 'If I fall, remember "
        "the Gap,' he wrote. 'Hold it with the strength of your father and "
        "let no man take the inheritance of our fields.' The words shook as "
        "he wrote them; velvet dusk pooled at the window and the king's "
        "hand trembled as he sealed the wax. He sent riders with the "
        "missives and watched them go, eyes like coals under ash.");

    addChapter("XXI - The Fall at the Gap",
        "Year 31: On a dawn like any other, the enemy pressed as with iron "
        "hands. Ulric fought at the foremost and, pierced by many, he fell "
        "within the dust and the cry. His captains held him between them and "
        "bore him from the field to where banners would cover him. The Gap "
        "was held by those who swore and by those who bled, and the king's "
        "last breath was a prayer for land and for sons. The keepers set a "
        "cairn and the women wailed. His name passed into the songs of the "
        "valley, no longer a living voice but a ringing refrain that would "
        "not be forgotten.");

    addChapter("XXII - The Hill Sings His Name",
        "They raised a cairn of stones upon the high ground and wove a "
        "shroud of his colors. Minstrels told of the oath and the last stand; "
        "mothers named children for him and farmers left a small stone by "
        "the road. Seasons turned and the hill kept his name like a "
        "slow-keeping thing. When north winds came, villagers said they "
        "could hear the rhythm of his march in the whistle of the grass. In "
        "that way Ulric's memory became a lodestar for those who would hold "
        "the line.");
}
