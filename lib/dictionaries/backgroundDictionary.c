//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping personalityQuestionnaire = ([
    "1":([
        "question": "You have been invited to attend a grand ball. All of the nobility\n"
            "will be there, though you do not know any of them. You are expected to\n"
            "mingle with them. Does this",
        "answers": ([
            "1": ([
                "name": "Excite and energize you. This is, after all, your element and you\n"
                    "          love meeting new people.\n",
                "type": "extravert"
            ]),
            "2": ([
                "name": "Fill you with a sense of dread. People suck and you really would\n"
                    "          rather stay home doing something far more interesting\n"
                    "          like rearranging your sock drawer. The thought of\n"
                    "          listening to the bemoanings of all these self-absorbed\n"
                    "          assholes you'll never see again just doesn't excite you.\n",
                "type": "introvert"
            ])
        ])
    ]),
    "2":([
        "question": "Your instructor likes to torment his students with inane activites. Today,\n"
            "he has assigned the task of adding all numbers from 1 to 1000. Do you",
        "answers": ([
            "1": ([
                "name": "Get on with it. If you hurry up and work through the problem as\n"
                    "          convention dictates, it shouldn't take too long ere you're done\n"
                    "          and able to move on to more enjoyable activities.\n",
                "type": "sensing"
            ]),
            "2": ([
                "name": "Reject convention. If you think about the problem for a while,\n"
                    "          you may well come up with a better way of solving the problem. Of\n"
                    "          course, maybe you won't and you could end up wasting time\n"
                    "          needlessly.\n",
                "type": "intuition"
            ])
        ])
    ]),
    "3":([
        "question": "You have gone to a village meeting wherein you are discussing two projects\n"
            "that are competing for the same resources: the building of a new well for\n"
            "irrigation or erecting a statue of Sir Whatshisname Of Whocares. Most there\n"
            "seem inclined to build the statue - he was the village founder, after all -\n"
            "but you think the well is the only sensible idea. Do you",
        "answers": ([
            "1": ([
                "name": "Thoroughly discuss all of the pros and cons of both projects and\n"
                    "          clearly detail why the well is the only logical choice.\n",
                "type": "thinking"
            ]),
            "2": ([
                "name": "Seek to understand why the others want the statue and work toward\n"
                    "          the consensus opinion in the end.\n",
                "type": "feeling"
            ])
        ])
    ]),
    "4":([
        "question": "As the leader of an expeditionary force, you have come across an enemy\n"
            "encampment. Through your reconnaissance, you have been able to clearly\n"
            "determine that they are planning to lead a campaign to loot and pillage\n"
            "your leige's lands. Do you",
        "answers": ([
            "1": ([
                "name": "Meticulously and methodically organize your plan of attack. You\n"
                    "          will only get one chance, so this had best be perfect.\n",
                "type": "judging"
            ]),
            "2": ([
                "name": "Prepare for the attack with those resources you have on hand. The\n"
                    "          plan may not be perfect, but it is not rigid and you trust in\n"
                    "          yourself to adapt as new information comes your way.\n",
                "type": "perceiving"
            ])
        ])
    ]),
    "5":([
        "question": "You have been hired by the local lord to track down and apprehend a war\n"
            "criminal. In time, you find the man - one of your old comrades-in-arms. As you\n"
            "are in the process of taking him back for judgement, you discover that his\n"
            "'crimes' involved turning on his lord when ordered to raze a town and butcher\n"
            "its citizens whose only crime was refusing to surrender their harvest to this\n"
            "lord's armies. He and four others defected and protected the townsfolk. In the\n"
            "ensuing melee, he was victorious though his companions all perished. Do you",
        "answers": ([
            "1": ([
                "name": "Honor your contract and bring the man to justice knowing that he\n"
                    "          faces executioner for acting with compassion and honor in\n"
                    "          protecting innocents.\n",
                "type": "loyal"
            ]),
            "2": ([
                "name": "Free him knowing that, at best, your quest will fail and at worst,\n"
                    "          your duplicity will be discovered.\n",
                "type": "compassionate"
            ]),
            "3": ([
                "name": "Take up arms against the local lord and bring him to justice\n"
                    "          before the king, knowing full well that the king would judge his\n"
                    "          deed the act of a criminal.\n",
                "type": "just"
            ]),
            "4": ([
                "name": "Inform the local lord that you have uncovered the true nature of\n"
                    "          the man's crimes and that you still intend to bring the man in but\n"
                    "          require additional money lest you inadvertently mention this\n"
                    "          episode to the king.\n",
                "type": "corrupt"
            ]),
        ])
    ]),
    "6":([
        "question": "Your travels have led you to a crypt. After vanquishing a wight, you\n"
            "find a vast, opulent treasure that will easily set you up for life. You take\n"
            "all you can and congratulate yourself for your good fortune. The next day while\n"
            "you are smugly sipping an ale in the local tavern, you hear that the local\n"
            "constable has arrested a man for ransacking the crypt. Do you",
        "answers": ([
            "1": ([
                "name": "Silently offer a toast to yourself. It appears that the treasure\n"
                    "          really is all yours!\n",
                "type": "dishonest"
            ]),
            "2": ([
                "name": "Turn yourself in. If you tell the constable what happened and\n"
                    "          return the treasure, it's no harm, no foul, right? They wouldn't\n"
                    "          execute you for this, would they? Regardless, you can't let that\n"
                    "          poor soul pay for your crime.\n",
                "type": "honest"
            ]),
            "3": ([
                "name": "You realize that life will be short for you if you're caught,\n"
                    "          but you can't let that poor bastard take the fall for you so...\n"
                    "          there's nothing for it but to plot a daring rescue. The jail\n"
                    "          doesn't look all that sturdy.\n",
                "type": "greedy"
            ])
        ])
    ]),
    "7":([
        "question": "You are a lord and have a long-standing dispute with a fellow noble - \n"
            "Ser Osis of D'Liver. She has gone to the king complaining about how she has been\n"
            "inconvenienced and insulted by you because you did not have your servant\n"
            "whipped when they accidentally spilled her glass of wine on the table. She\n"
            "demands an apology. You respond",
        "answers": ([
            "1": ([
                "name": "Ser Osis of D'Liver can kiss my arse. That wretched dung-beast\n"
                    "          spilled her own wine!\n",
                "type": "vulgar"
            ]),
            "2": ([
                "name": "Ser Osis of D'Liver is a drunkard and a buffoon. I will not punish\n"
                    "          others for her inability to hold her liquor.\n",
                "type": "abrasive"
            ]),
            "3": ([
                "name": "The kind of woman who wants to enforce her ideas on others is\n"
                    "          the kind of woman whose ideas are idiotic.\n",
                "type": "witty"
            ]),
            "4": ([
                "name": "Ser Osis of D'Liver believes in the ideal that her birthright\n"
                    "          allows her to step on others. An idealist is one who, on\n"
                    "          noticing that a rose smells better than a cabbage, concludes\n"
                    "          that it also makes a better soup.\n",
                "type": "orator"
            ])

        ])
    ]),
]);

private mapping backgrounds = ([
    "elf":([
        "wood elf": ({ "scout", "apprentice" }),
        "grey elf": ({ "noble", "apprentice", "smith", "artist", "musician", "scribe", "merchant" }),
        "sea elf": ({ "noble", "mariner", "merchant", "smith", "apprentice" }),
        "dark elf": ({ "noble", "apprentice", "smith" }),
        "none": ({ "apprentice", "smith", "artist", "musician", "scribe", "merchant" })
    ]),
    "dwarf":([
        "khazurathi dwarf": ({ "noble", "soldier", "smith", "merchant" }),
        "mirosti dwarf": ({ "noble", "soldier", "smith", "merchant" }),
        "none": ({ "soldier", "smith", "merchant" }),
    ]),
    "draconid":([
        "none": ({ "noble", "apprentice", "smith", "artist", "musician"})
    ]),
    "maegenstryd":([
        "none": ({ "noble" })
    ]),
    "halfling":([
        "none": ({ "scout", "farmer", "merchant", "musician", "artist" })
    ]),
    "gnome":([
        "none": ({ "noble", "apprentice", "smith", "artist" })
    ]),
    "half elf":([
        "none": ({ "scout", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue" })
    ]),
    "half orc":([
        "none": ({ "scout", "soldier" })
    ]),
    "half troll":([
        "none": ({ "scout", "soldier" })
    ]),
    "faerie":([
        "none": ({ "noble", "scout", "apprentice", "musician" })
    ]),
    "human":([
        "eledhelean": ({ "noble", "mariner", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "hillgarathi": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "tirnosti": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "menadrosti": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "iarwathean": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "helcarish": ({ "noble", "mariner", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "celebnosti": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "andurathi": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "linmiri": ({ "noble", "mariner", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "endurgish": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "zhenduli": ({ "noble", "scout", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" }),
        "none": ({ "scout", "mariner", "soldier", "farmer", "smith", "apprentice", "merchant", "musician", "artist", "rogue", "scribe", "acolyte" })
    ]),
    "high elf":([
        "half elf": ({ "noble" }),
        "hillgarathi elf": ({ "noble", "apprentice", "smith" }),
        "moon elf": ({ "noble", "mariner", "smith", "apprentice" }),
        "none": ({ "mariner", "apprentice", "smith" }),
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask mapping personalityQuestionnaire()
{
    return personalityQuestionnaire + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setPersonalityArchetype(object user, string *results)
{
    string trait = "";
    foreach(string result in results)
    {
        trait += result[0..0];
    }
    
    user->addTrait(sprintf("/lib/instances/traits/archetypes/%s.c", trait));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateUserPersonality(object user, string *results)
{
    setPersonalityArchetype(user, results[0..3]);
    results = results[4..];

    foreach(string result in results)
    {
        user->addTrait(sprintf("/lib/instances/traits/personality/%s.c", result));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateBackground(object player)
{
    object background = 
        load_object("/lib/dictionaries/backgrounds/eledhelNobleBackground.c");

    background->initiateBackgroundStory(player);
}
