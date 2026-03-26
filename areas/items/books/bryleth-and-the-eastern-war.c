//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bryleth Ascendant");
    set("short", "A book titled 'Bryleth Ascendant'");
    set("title", "Bryleth Ascendant");
    set("aliases",
        ({ "heroic ages", "eledhel saga", "eastern mythic history", "book", 
            "bryleth ascendant" }));
    set("long",
        "A mythic account of the Eastern Lands, blending deeds, speeches, and legend. "
        "Kings and queens speak, battles roar, and cities rise amid shadow and fire.");

    addChapter("Bryleth Ascendant",
        "The tale begins with Bryleth, radiant and unbowed.\n"
        "Elonoch III, mighty in battle, fell by her hand.\n"
        "The kingdom trembled. Courtiers whispered of wrath divine.\n"
        "Bryleth mounted the throne, eyes blazing, hair like fire.\n"
        "'Let none doubt my hand! I walk where gods feared to tread,' she cried.\n"
        "'I have claimed what is mine by blood, by fire, and by will.'\n"
        "To west and east she granted peace, yet none dared doubt her.\n"
        "Legends say her counsel split mountains, her gaze stopped armies.\n"
        "Linwaeth arose under her decree, bright city of hope and strength.\n"
        "Andurath's banners clashed with Kharand, thunder shaking the plains.\n"
        "The kings of men knew that fate favored no mortal hand.\n"
        "Bryleth smiled, her shadow stretching over every hall.\n");

    addChapter("The Shadow of Utumnadh",
        "A darkness rose in Utumnadh, a godless terror unseen.\n"
        "Allied kings gathered, swords drawn, shields shining.\n"
        "'Strike as one! Let the enemy see the banners of unity and dread,'\n"
        "they roared. The battle raged like storm and fire.\n"
        "Mirost's king fell, Hillgarath's crown shattered in flame.\n"
        "Eledhel mourned, yet Bregandil's son lifted the standard high.\n"
        "'From ashes and exile, Eledhel rises like the dawn,' he bellowed.\n"
        "Azgurdain II of Mirost, Aegdren of Hillgarath, Finwendil of Eledhel.\n"
        "They stood as pillars while the dark power cowered.\n"
        "The menace ceased, yet the cost carved sorrow into every heart.\n"
        "Old songs remember the cries, the fire, and the fallen.\n"
        "Ellatan assumed Eneldhor's crown, weaving peace from ashes.\n");

    addChapter("Plague and Sorrow",
        "The wind carried a foul whisper from south of Linmir.\n"
        "Plague descended, burning through villages, leaving silence.\n"
        "Fields lay empty, and cattle fell like stones.\n"
        "Children cried in streets where mothers had vanished.\n"
        "King Elandur wept over Eneldhor, yet his tears could not stop it.\n"
        "'Though plague and shadow fall, Eledhel shall rise unbroken,' said Armadil.\n"
        "Maunladir of Hillgarath sent healers and prayers to the heavens.\n"
        "Even Bryleth, far from mortal reach, felt the shadow of suffering.\n"
        "The land itself seemed to mourn, rivers swollen, skies heavy.\n"
        "Yet from the ashes, new settlements would rise, tempered by grief.\n");

    addChapter("Succession of Kings",
        "Elandur's hand passed, and Eneldhor found new hope.\n"
        "Armadil ruled Eledhel with courage and cunning.\n"
        "'Our swords speak louder than whispers of fear,' he proclaimed.\n"
        "Maunladir held Hillgarath firm, shields and spears gleaming.\n"
        "'Hillgarath stands as mountain, unmoved by storm or blade,' he shouted.\n"
        "The kings spoke of unity, yet each heart beat for its own crown.\n"
        "Couriers rode like lightning to bring tidings of alliances and oaths.\n"
        "The people murmured songs, heralding new rulers as legends in waiting.\n"
        "Yet the memory of Bryleth lingered, her shadow long and unbroken.\n"
        "The old queen's cunning whispered through every hall and council.\n");

    addChapter("The Rise of Lonisiach",
        "Celebgaer and Gildaer cast off Kharand's yoke, forging Lonisiach.\n"
        "City-states arose like sparks from a dying flame.\n"
        "Bryleth's hand, though absent, guided some, punished others.\n"
        "'No darkness shall claim this land while my blood flows in the\n"
        "veins of men,' Bregandil swore.\n"
        "Walls rose high, markets filled with voices from distant lands.\n"
        "Kharand fractured, many rulers claiming dominion over scraps.\n"
        "Lonisiach was a beacon of resilience, forged from upheaval.\n"
        "Songs were sung of Bryleth's cunning, her wrath, and the age she commanded.\n"
        "Even as empires fractured, the tales of her deeds traveled faster.\n"
        "The citizens lit torches in honor of the queen who shaped the world.\n");

    addChapter("Whispers of the Scions",
        "Scholars in quiet halls noted: 'No mortal woman could endure so long.'\n"
        "Bryleth's reign was measured in centuries, her mind sharper than swords.\n"
        "The Scions recorded omens, noting cracks in thrones and hearts.\n"
        "Her name became myth, feared and revered, in every corner.\n"
        "'Long shall my name endure, beyond men, kings, and memory,' she had boasted.\n"
        "Even kings of Eledhel trembled when her shadow fell across the land.\n"
        "Lonisiach's founding was whispered to bear her blessing and her curse.\n"
        "Every tale of triumph and survival carried a hint of her influence.\n"
        "The chroniclers warn: remember her, for she shaped the world unseen.\n"
        "And in every saga, her shadow lingers, longer than stone or crown.\n");
}
