//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A battered leather notebook");
    set("short", "A battered leather notebook");
    set("title", "The Journal of Nilas, Knight of the Order of the Night");
    set("aliases", ({ "notebook", "journal", "battered notebook",
        "leather notebook", "nilas journal", "nilas notebook", "book" }));
    set("long", "A small, battered notebook bound in cheap leather "
        "stained with salt spray and what might be blood. The pages "
        "are filled with cramped, angular handwriting. The author "
        "identifies himself as 'Nilas, of the Order of the Night.' "
        "The entries are dated in the months of Murath and Dulath, "
        "Year 2942.");

    addChapter("14 Murath - The Assignment",
        "14 Murath 2942: That bitch Gelia ordered me on to the "
        "front today. Funny how she cowers behind the Nightmaster "
        "whenever danger rears its head. On the morrow, we land "
        "at Helcarion.");

    addChapter("14 Murath - The Voyage",
        "14 Murath 2942: This trip is intolerable! One of the "
        "rabble in Sullath's army dared approach me with sundry "
        "questions about the morality of the Orsirish See and how "
        "it relates to the heresy of Kirloth. I told him flatly "
        "that the Queen is one and her Nightmaster is her mortal "
        "conduit onto this plane. He pressed the issue claiming "
        "that the Nightmaster is her own person and but receives "
        "counsel from the Queen. The Nightmaster then, is NOT in "
        "any way divine and could feasibly be a male.");

    addChapter("14 Murath - The Voyage, continued",
        "I dispatched the sot to Seilyndria where all his "
        "questions may be answered forthwith. 'Twas amusing "
        "seeing the sailors quibble about the cause of his "
        "death. I hate this wretched boat, or rather, I hate "
        "being closeted with all of these semi-evolved cretins. "
        "Their sloping simian foreheads and bushy brows make me "
        "want to vomit. Why we must entertain these evolutionary "
        "mistakes is beyond me.");

    addChapter("15 Murath - Landing at Helcarion",
        "15 Murath 2942: This trip appears to have its merits "
        "after all. We found Nightblade! It was borne by some "
        "imbecile who thought he might bargain with the "
        "Nightmaster! For all of her beauty, I wouldn't fawn "
        "upon her as he did. I get ahead of myself. We landed "
        "near Helcarion early in the morn. I was in the vanguard "
        "with Sullath and we came across two witlings riding on "
        "the road - right into our arms.");

    addChapter("15 Murath - The Arrest",
        "'Drop your weapons if you wish to live.' shouted the "
        "so-called lord Sullath. 'Be assured, there is no "
        "escape...' This he said when he saw the two men "
        "hesitating. One looked to be the typical rascally sort, "
        "an unclean brute with a sneering face. The other, "
        "apparently the brains of the outfit, was a greasy "
        "fellow - perhaps a dunadan, though obviously a fallen "
        "one.");

    addChapter("15 Murath - Nightshade Speaks",
        "At any rate, the two looked as though they had seen a "
        "ghost. The greasy one, who later called himself "
        "Nightshade, asked, 'Is there a face to the voice that "
        "addresses us? Show yourself to us. You've clearly got "
        "us outnumbered, man.' I tell you, just hearing his "
        "voice, I felt the need to bathe. Ere the wretch could "
        "finish his speech, Sullath shot his mount out from "
        "under the fellow.");

    addChapter("15 Murath - Sullath's Arrogance",
        "The dolt has the nerve to say, 'Was it really necessary "
        "to shoot my mount?' asks Nightshade in somewhat "
        "condescending tones. 'A simple halt or die would have "
        "sufficed.' You could clearly see him shaking though.\n\n"
        "'Twas regrettable, but he was aiming for you.' laughed "
        "Sullath. 'Good gentlemen, you are under arrest. By "
        "order of the Lord Sullath, this road is closed to "
        "travel.' Imagine his impertinence - he feels the need "
        "to talk of himself in the third person.");

    addChapter("15 Murath - Orders Given",
        "Sullath looks at Cerinath and orders, 'Bind and search "
        "these two and send them to me in an hour. Also, send "
        "for Vilias. I think she will be interested... We make "
        "camp today. On the morrow, we take Helcarion.' Smiling "
        "at the two prisoners, he adds, 'My men would prefer "
        "that you resist... they have been found wanting for any "
        "form of amusement of late.'");

    addChapter("15 Murath - The Nightmaster Appears",
        "Unexpectedly, Vilias appeared at this time. By the "
        "gods! She is a thing of beauty. Those pale blue eyes "
        "of hers tear at my soul whenever we meet. That lush "
        "black hair and her pert, perfect nose... those lips... "
        "aye, she can both pierce the soul and charm the heart. "
        "She can prance about with innocent grace or prowl as "
        "the beast ready to slay... Today, it looked like she "
        "would have fun with her prey.");

    addChapter("15 Murath - Vilias Examines the Prisoners",
        "Guard Cerinath cowered ever so slightly as he saw "
        "her... no doubt remembering the thrashing he bore last "
        "time they met.\n\n"
        "'This one carried Nightblade?' she crones prodding at "
        "Nightshade - the apparent name of the oily one.\n\n"
        "'Yes, milady...' replies Cerinath.\n\n"
        "'Excellent!' Vilias says, her perfect teeth showing "
        "amongst her beautiful smile.");

    addChapter("15 Murath - Vilias Speaks to the Prisoners",
        "'One often wonders about this untrusting world, no?' "
        "she begins with a smirk as she stares icily at the "
        "two prisoners. 'I truly regret that I felt the need to "
        "render you two immobile. One can never trust the minds "
        "of desperate men. You may speak if need be; nay, I "
        "require it.'\n\n"
        "'Ah, whatever. You don't have any Keepers of the Night "
        "around, do you?' asks the impudent Nightshade.");

    addChapter("15 Murath - Nightblade and Zylia",
        "Vilias looks at Nightshade in amusement, a strange "
        "glint of mischief in her eyes. She smiles sweetly and "
        "purrs, 'What else do you two carry?' She ignores the "
        "inquiry and probes their minds. I have often wondered "
        "what secrets she must carry... Eyes sparkling with "
        "amusement, she turns to the other and asks, 'What "
        "bauble rests upon your hand?' She smiles as she looks "
        "at Cypress, the rascal. Clearly she is enjoying "
        "herself. Releasing an almost inaudible gasp, her smile "
        "broadens. 'Seilyndria blesses me mightily. Nightblade "
        "and Zylia are among us!'");

    addChapter("15 Murath - Before the Interrogation",
        "15 Murath 2942: I was invited to sit in on the "
        "interrogation of the prisoners. Sullath wanted "
        "everything scribed. He seems wary of the Nightmaster. "
        "I know not why. She is the morning dew collected into "
        "nectar sweet and wondrous. I well-nigh burst with "
        "excitement upon hearing that she would grace our "
        "presence. It shall happen after evening meal.");

    addChapter("15 Murath - Inventory: Nightblade",
        "I, Nilas, of the Order of the Night, do hereby record "
        "the interrogation of one Cypress Alouisos and one "
        "Nightshade Delgorth, two enemies of the order. In Lord "
        "Sullath's possession lie several items from the "
        "prisoners:\n\n"
        "Nightblade - 'tis an impressive jagged-bladed two "
        "handed sword fashioned of that rare black metal known "
        "as 'galvorn'. It is nearly 6 feet in length and bears "
        "a hilt fashioned out of a midnight blue crystal. The "
        "make of this is unknown to our sages. The hilts have "
        "been fashioned into a dragon's claw.");

    addChapter("15 Murath - Inventory: Nightblade's Power",
        "It emanates immense power... I have been assured by "
        "the Nightmaster that this weapon collects the souls of "
        "its victims and uses this fuel to perform deeds of "
        "incredible power. Truly, it is a weapon of "
        "intimidation and incredible strength.");

    addChapter("15 Murath - Inventory: Zylia and Anguruth",
        "Zylia - This incredible ring has been forged of a "
        "pale blue crystal, apparently kirluin. It is fashioned "
        "of a dragon as if the beast were wrapped around a "
        "finger. The detail is exquisite, looking as though the "
        "dragon could unfurl and spring into flight at any "
        "moment. The eyes... they appear to be fashioned of "
        "sapphires that catch the light in a most incredible "
        "fashion. The ring quite obviously holds exceptional "
        "powers.");

    addChapter("15 Murath - Inventory: Other Effects",
        "Anguruth - This is the sword of Cypress. It appears "
        "to have been crafted of mithril! It is a weapon "
        "roughly 50 inches and quite clearly is an ancient "
        "blade of the Numenorians.\n\n"
        "A few other trinkets of marginal use, including a "
        "worn book on Corporum. Apparently Nightshade fancies "
        "himself a necromancer. Also of note are some swords "
        "that bear the mark of the Order of the Storm.");

    addChapter("15 Murath - The Interrogation Begins",
        "Knight Sullath sits in a comfortable chair and, upon "
        "seeing the guards bringing the two in, says, 'Sit "
        "them down over there and leave us.' He motions to two "
        "wooden chairs. 'I have been given a repor...'\n\n"
        "'We have a most extraordinary situation here.' says "
        "Vilias gaily as she flits in. She briefly ruffles "
        "Nightshade's hair with her delicate, feminine fingers "
        "as she walks past. 'Yes, most wonderful indeed.' With "
        "a musical laugh, she sits down on the table.");

    addChapter("15 Murath - Sullath Confronts Vilias",
        "Looking rather annoyed, Sullath grits his teeth and "
        "says, 'I am in charge of this interrogation, bitch. "
        "You will respect this fact! I command this army.' "
        "Vilias's smile broadens and she beams, 'I didn't "
        "realize that you were here! Dearest Sullath, forgive "
        "me my lack of manners!' Vilias glances at the "
        "prisoners and winks, assuring herself that they won't "
        "ruin her little game by doing something as stupid as "
        "trying to escape. Oh how she enjoys goading the "
        "jarheads around here.");

    addChapter("15 Murath - Vilias Asserts Herself",
        "Bristling with rage, Sullath growls, 'You mock me.' "
        "He stands and moves his hand to his sword. Snaking "
        "her head around, Vilias stares directly into Sullath's "
        "eyes, causing the man to pause, fear very plainly in "
        "his visage. Shaking visibly, he falls back into his "
        "chair. 'I do indeed, Field Commander.' she says with "
        "a hiss, 'Do not forget for a second that you live "
        "because I choose to let you. Not even Dalthus is "
        "stupid enough to question me! You are but an "
        "insect...'");

    addChapter("15 Murath - Vilias Questions Nightshade",
        "With a grumble Sullath forces himself to say, 'I "
        "apologize, Nightmaster.' Dismissively raising a hand "
        "and smiling again, Vilias demurs, 'Nightshade. Hmmm. "
        "'tis an interesting name indeed. I note from your book "
        "that you study the necromantic arts.' Her voluminous "
        "eyes fully engaged with Nightshade's, she continues. "
        "''Tis a pity you chose to waste your potential on such "
        "trivialities.'\n\n"
        "'I suppose that you two are wondering why you're "
        "here?' Vilias asks coyly. 'Perhaps I can enlighten "
        "you.'");

    addChapter("15 Murath - Sullath's Charges",
        "'M'lady, if I may interject here.' begins Sullath, "
        "trying to regain control over the meeting. 'These two "
        "were found with several weapons on them that had "
        "formerly belonged to knights of the storm. We also "
        "found several bodies -- one of them being Subcommander "
        "Findras. I believe also that two of your acolytes, "
        "Ulfith and Nelthor, were among the slain. Now, murder "
        "or grave robbery would both carry the sentence of "
        "death. It is my right as commander of this army to "
        "carry this judgement out.'");

    addChapter("15 Murath - Vilias's Amusement",
        "Rolling her eyes, Vilias coos, 'I'm sure that poor, "
        "misunderstood Nightshade was only gazing up at the "
        "clouds when that clumsy oaf Findras tripped and fell "
        "on Nightblade...' grinning wickedly, she turns and "
        "looks at Nightshade, 'Alas, though, Seilyndria has "
        "long ago condemned you to death.' Looking briefly at "
        "each prisoner and then turning back to Sullath, she "
        "adds, 'Still, I'm interested in their story.' Eyes "
        "growing dark, she slinks off to Nightshade and grabs "
        "him by the neck, squeezing ever so gently. 'Now tell "
        "me,' she hisses, soft malice in her voice, 'why are "
        "you here?'");

    addChapter("15 Murath - Nightshade's Tale, Part I",
        "'Gladly will I recount for you my reason for being "
        "here. I hope, in exchange, to understand why I've been "
        "so hounded by your forces. This does present me with a "
        "great deal of confusion as I certainly bear you no ill "
        "will. In fact, I wish you all godspeed in your conquest "
        "against the insufferable Werrics. The short reason that "
        "I'm here, is that, well, your forces captured and "
        "detained my friend and I. I've been pursued by your "
        "forces recently, apparently because I own Nightblade, "
        "and I believe this to be the issue you most wish to "
        "hear about.'");

    addChapter("15 Murath - Nightshade's Tale, Part II",
        "'My master in the black arts was a cruel and hard man. "
        "Not so surprising a thing considering what he dealt in, "
        "but I gladly bore his torments to be his pupil. I found "
        "that I was quite adept and learned quickly. My master "
        "would occasionally parade around with a tremendous "
        "blade that he barely had the strength to lift, let "
        "alone wield. I think the blade tolerated him at best. "
        "Anyhow, I know not how he came by the sword, only that "
        "he called it the Nightblade. He even used it in my "
        "lessons, revealing to me its powers and how to wield "
        "them, though I could not actually touch the blade "
        "myself.'");

    addChapter("15 Murath - Nightshade's Tale, Part III",
        "'As I progressed in my studies, I began to have "
        "dreams. At first they seemed mere coincidence. I saw "
        "myself in black leathers, wearing a cape, my hair "
        "blown and tossed about by some chill otherworldly "
        "breeze. And there I stood, a sword in my hands. My "
        "frame is rather suited to the martial pursuits, and "
        "soon I began to also practice with some blades my "
        "master kept around. I proved handy enough with steel, "
        "but I knew my true talent lay in the magical arts.'");

    addChapter("15 Murath - Nightshade's Tale, Part IV",
        "'Soon, I knew from my dreams and from the sensations I "
        "had from the blade that it called me. One night, I "
        "crept into my master's lab after he and Arfed were "
        "asleep. He left the blade out, knowing full well no "
        "one could take it. The fool. I cautiously reached for "
        "the blade, and when it didn't drive me to the ground "
        "in agony, I knew Nightblade had not only accepted me, "
        "but had taken a new owner. Fearing my master's wrath, "
        "I quickly packed my things and fled.'");

    addChapter("15 Murath - Nightshade's Offer",
        "'I suppose you could kill me and take the blade. I "
        "don't believe the blade would take a new master from "
        "among you. I suppose you, or one of your lieutenants, "
        "could impose your will onto the weapon. This would "
        "take great effort, and the blade would still strive "
        "against you. Now then - Nightblade does not oppose "
        "you, and if you desire its service, why, I'm the man "
        "to talk to. Heal my hand here, and properly equip me, "
        "and name your reasonable service.' The wretch oozes "
        "with slime. His slick-talking manner does little to "
        "sway the lovely Vilias.");

    addChapter("15 Murath - Vilias Gives Sullath the Blade",
        "Smiling wryly, Vilias bites down on her lower lip.\n\n"
        "Giggling, Vilias picks up Nightblade. 'Here Sullath. "
        "I have a trinket for you!' She hands the blade to "
        "Sullath.\n\n"
        "Sullath cautiously touches the blade, expecting to get "
        "zinged. With a look of disbelief, he holds onto the "
        "blade. 'Has it chosen a new master then?'\n\n"
        "With a sweet smile, Vilias looks at Nightshade and "
        "says, 'I bet you would just love to know the answer "
        "to that question?' Nightshade frowns but says nothing.");

    addChapter("15 Murath - Vilias's Rebuke",
        "Sullath snorts and says, 'His tongue flaps freely. No "
        "doubt he would turn around and tell the Werrics all if "
        "it suited his purpose which, to me, seems to be "
        "self-preservation.'\n\n"
        "Vilias looks at Nightshade capriciously and muses, "
        "'And what a noble pursuit...' her amused look "
        "vanishing, she peers darkly at Nightshade. 'You "
        "mentioned your interest in the Keepers of the Night. "
        "Do you not realize that they are the enemy? Yet you "
        "try to gain favor by mentioning them to me?'");

    addChapter("15 Murath - The Weak and Their Toys",
        "'Yes, you're a brazen one... to kill you would be such "
        "a waste.' Vilias demurs, the laughter plainly showing "
        "in her eyes. 'As you can see, there will be no trouble "
        "in finding someone capable of wielding Nightblade. Does "
        "that bother you?' She gazes deep into Nightshade's "
        "eyes.\n\n"
        "With a heartfelt laugh, Vilias continues, 'I can "
        "oh-so-plainly see that it does! The weak are often "
        "upset when their toys get taken away. Nay... even the "
        "gods are! Do not think for a moment that I did not "
        "notice your attempt at sending Findras into Xyris's "
        "camp.'");

    addChapter("15 Murath - Cypress's Death",
        "'Milady, they should...' begins Sullath.\n\n"
        "'Leave us!' growls Vilias.\n\n"
        "'That one?' questions Sullath, pointing at Cypress.\n\n"
        "Rage consuming her, Vilias points her finger at "
        "Cypress. 'You want someone to pay for the so-called "
        "crimes against your army. He will suffice.' Eyes now "
        "glowing brilliantly, Vilias points at Cypress.\n\n"
        "Cypress's body shrivels into a lifeless husk next to "
        "Nightshade, as if all of the moisture has been sucked "
        "from his body by a spider. With a gasp of "
        "ill-contained horror, Sullath salutes Vilias and "
        "leaves. Alas that I cannot.");

    addChapter("15 Murath - Vilias's Sentence",
        "Smiling again, Vilias looks at and approaches "
        "Nightshade, gently touching his chin. 'Give me your "
        "hand.' she purrs, pointing at his splinted arm. "
        "Nightshade silently obeys. With a quick snap of her "
        "wrist, she breaks the ulna. 'Your arrogant demand is "
        "denied! Yet, you will not die. Does that please "
        "you?'\n\n"
        "Nightshade glares daggers at her. Grinning wickedly, "
        "eyes full of malice, Vilias says, 'I shall send you "
        "to the halls... Yes, the gods do need their toys...' "
        "With a flash, Nightshade is gone.");

    addChapter("15 Murath - Nightblade Is Mine",
        "Picking up the ring Zylia, she smiles, 'Perhaps Gelia "
        "will find this useful.' Vilias looks at me, and smiles "
        "such that I am enthralled. 'Forgive me for putting you "
        "through that unpleasant business. It has its own reward "
        "though. You may bear Nightblade.' With that, she walks "
        "away.");

    addChapter("16 Murath - I Find the Blade",
        "16 Murath 2942: I have found the Nightblade! A "
        "disagreeable dunedain scum carried it in the pathetic "
        "militia of Tineas. I felled the weakling myself and "
        "wrested the blade from him myself. It is mine and mine "
        "alone. Oh, the sword... It is a two-handed sword with "
        "an incredible jagged blade. 'Tis about six feet long "
        "and made of the metal the orcs call ascuil. The hilt "
        "is cool to my touch and is fashioned of an "
        "undiscernible crystalline material. It is midnight blue "
        "in nature and seemeth to release its own light. It has "
        "been shaped to the form of a dragon's claw.");

    addChapter("20 Murath - Vilias's Counsel",
        "20 Murath 2942: I have discussed the matter of the "
        "blade with Nightmaster Vilias. She has assured me of "
        "its worth and rewards me greatly. The blade has proven "
        "far more important than I realized. The Nightmaster is "
        "quite beautiful and I find it difficult to concentrate "
        "on the matter at hand... this always happens when she "
        "speaks to me. Gelia looks like her in many ways... why "
        "then, does one fill me with weak-minded lust whilst "
        "the other fills me with hatred?");

    addChapter("21 Murath - The Blade's Powers",
        "21 Murath 2942: I hath composed myself. Nightmaster "
        "Vilias told me that the blade has the ability to "
        "shatter any weapon it cometh into contact with, become "
        "as if made of the energies of magic and pass through "
        "armor as if it were of no consequence, leech out the "
        "life of those it strikes, and summon the energies of "
        "the souls it has taken. The souls are imprisoned in "
        "the blade and, when unleashed, can cause incredible "
        "devastation. On another note, we take Morthysse "
        "tomorrow.");

    addChapter("22 Murath - Morthysse Falls",
        "22 Murath 2942: The Nightblade deeply vexes me and I "
        "can think of little else. Its cold touch beckons me "
        "-- to what great deeds, I know not. The city of "
        "Morthysse fell quickly and Nightblade drank deeply of "
        "the wretched masses. 'Tis amazing to see the souls of "
        "its victims become captured by the blade. I feel a "
        "soothing kinship with the blade.");

    addChapter("23-25 Murath - Blood and Conquest",
        "23 Murath 2942: Aragim is dead by my hands. I felt "
        "his inquiring eyes on my prize and had little choice. "
        "I rest more easily with his soul in my keeping.\n\n"
        "24 Murath 2942: On the morrow, we cross Theilyss Bay "
        "and take Tol-Ithyl.\n\n"
        "25 Murath 2942: Tol-Ithyl has fallen. The blade... "
        "it grows on me.");

    addChapter("28 Murath - Vargath",
        "28 Murath 2942: We march on Vargath tomorrow. That "
        "wretched arms dealer will pay for his treachery.");

    addChapter("29 Murath - The Blade Is Taken",
        "29 Murath 2942: Last night, I nearly slew the "
        "Nightlord Dalthus. The Nightmaster Vilias sent word "
        "to him of the accursed Nightblade. He ordered me to "
        "surrender it as he felt it had taken over my mind. To "
        "the abyss with him, I found myself thinking. I readied "
        "myself to strike but he wrested the blade from me. I "
        "instantly felt destroyed, but the feeling soon passed. "
        "It appears that I had all but fallen prey to the "
        "blade. I have received Vilias's blessing and shall "
        "sleep well tonight. I do hope that Dalthus proves a "
        "stronger owner than I.");

    addChapter("1 Dulath - Dol-Cuarath",
        "1 Dulath 2942: I neglected to note that we are still "
        "in Dol-Cuarath. The supply line has been "
        "re-established and we ride out to Vargath tomorrow.");

    addChapter("2 Dulath - The Arms Dealer",
        "2 Dulath 2942: That accursed Vargath lives another "
        "day. Vargath... that name will soon be of little "
        "matter, yet I curse him daily. Vargath, arms dealer, "
        "swindler of no grace. We ordered 610 swords be "
        "delivered ere we reached Morthysse. He came, but with "
        "unacceptably low-grade iron, not the highly polished "
        "steel we paid for. This transgression has hindered our "
        "readiness for the war effort and his failure is "
        "unacceptable. The stupid man will be shown the tender "
        "mercy of Her Dark Majesty.");

    addChapter("3 Dulath - Dor-Cathrim",
        "3 Dulath 2942: Dor-Cathrim has fallen. It was not an "
        "intended target as it bears little importance. Nay, it "
        "was taken for its close proximity to Vargath and "
        "Orothysse. If it did not fall, Orothysse might well "
        "be warned of our presence... or worse, Eledhel. The "
        "high cleric of accursed Werra, Celedrath could well "
        "make matters difficult for us. Our spies indicate that "
        "he's in residence in Eledhel. Aye, I would not wish "
        "to confront him!");

    addChapter("4 Dulath - Vargath's End",
        "4 Dulath 2942: Vargath is dead. This has proven to be "
        "a minor issue, for we have fled from the mighty Sir "
        "Kellgaard today. Nay, Dalthus is no match for that "
        "one's skill - one of those wretched high elves who refuse "
        "to leave this world. Go back to live with your gods, "
        "I say. Still, we shall teach them not to leave their "
        "homes unattended. We march in haste to Orothysse.");

    addChapter("5 Dulath - Orothysse Falls",
        "5 Dulath 2942: Our Queen blessed us when one of those "
        "rat whelp halflings approached and distracted "
        "Umbrithel, high magus and lord of Orothysse. His "
        "defenses down, Dalthus was able to send the cleric to "
        "Werra's side. The meddlesome Kellgaard appears to "
        "have also been slain in that moment. Our glorious "
        "Queen looked upon us with favor today; a testament to "
        "our status as the chosen. Dalthus rode in glory with "
        "Angladhrim, that is the Quenya name for the "
        "Nightblade. He is truly the avatar of my Queen.");

    addChapter("5 Dulath - The Undead Attack",
        "5 Dulath 2942: The night after the victory at "
        "Orothysse we were camped outside of Orodyn. At "
        "unawares, we were attacked! Not by villagers from "
        "Orodyn as we'd first thought, but by those out of "
        "Orothysse! When battle closed, we found to our "
        "eternal shock that it was the undead that we faced! "
        "That meddlesome god of refuse Xyris is apparently "
        "against us!");

    addChapter("6 Dulath - The Sack of Serach",
        "6 Dulath 2942: Serach fell with barely a fight. We "
        "have herded the citizens to the center of town and "
        "await nightfall. Dalthus will draw the knights from "
        "their keep in the hour after sunset. It will be a "
        "glorious night for her dark majesty.");

    addChapter("6 Dulath - Dalthus Fails",
        "6 Dulath 2942: Damn them! That incompetent bastard "
        "Dalthus has failed; for the knights were far more "
        "prepared than expected. They nearly stole our prize "
        "from our grasp... The fools! I managed to destroy the "
        "knight. I now have the ring Elsyra in my "
        "possession... Nay, not even Dalthus will hear of "
        "this.");

    addChapter("6 Dulath - The Ring Elsyra",
        "The ring Elsyra is made of some strange red "
        "crystalline material of a nature I have never before "
        "seen. The thing has been fashioned into the form of a "
        "dragon... Truly, it appears as if the dragon curls "
        "around the finger of the wearer. In many ways, it "
        "reminds me of Zylia. That fool Algarion thinks that "
        "the ring he wears is Elsyra. I've encouraged him -- "
        "whelp hasn't studied at all. The ring is not metallic "
        "in nature. Still, I decry that something is unusual "
        "about that ring. Perhaps I will kill him today and "
        "find out exactly what nature it is.");

    addChapter("7 Dulath - To Linwaeth",
        "7 Dulath 2942: Dalthus lives. He was forced to the "
        "west -- no doubt back to Orothysse. The sack of "
        "Serach complete, it is unlikely that he will return, "
        "for the battle of Arnost must be prepared for and, "
        "indeed, expedited by 10 Aerath. A small contingent of "
        "knights survived the battle last night and are now "
        "under my command. Likewise, brother Urlen has "
        "accompanied me. Linwaeth and Eledhel must fall within "
        "the week or the delays could ruin us.");

    addChapter("7 Dulath - Linwaeth Secured",
        "7 Dulath 2942: Linwaeth secured, Vilias will be "
        "joining me on the morrow! I am far too excited by "
        "this news to work on my studies... perhaps...");

    addChapter("8 Dulath - Rejection",
        "8 Dulath 2942: Rejection. That bitch has sent me off "
        "with Algarion, Urlen, and two thrice-damned initiate "
        "knights to scout by Eledhel. Of all places! The "
        "fickle-minded wench has passed me off with a "
        "disconsolate wave. 'I sense an unusual disturbance "
        "approaching from the north. I want anyone you discover "
        "taken ALIVE! Fail in this and you will answer to the "
        "Queen.' She threatened me! How dare she? Bah! she "
        "shows no interest in me... perhaps I've deluded myself "
        "this whole time.");

    addChapter("8 Dulath - Defiance",
        "8 Dulath 2942: We met a small group of Werra's "
        "knights on the outskirts of Linwaeth. They have all "
        "been slain, Nightmaster's orders be damned. I have "
        "sent word to her that, should she feel the need, she "
        "can take herself to that place and bring them back to "
        "life herself.");
}
