//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void MaiwynIntroduced()
{
    addTopic("first conversation", "@D@A rather surprised-looking woman "
        "dressed in a dirty tan-ish shirt and equally dirty pants stands "
        "before you. Her garments are both made of coarse, thread-bare linen "
        "and show signs of excessive mistreatment. There are many stains - "
        "some of blood and some of what appear to be porridge. She smells of "
        "sweat, urine, feces, and rotting food. Her auburn hair is disheveled "
        "and rather filthy. Dirt, bruises, and abrasions mark her face. "
        "All of the abuse and neglect does not obscure the fact that she "
        "is an incredibly attractive woman. Her pale blue eyes open a window "
        "into a tortured, despairing soul. She shakily, but menacingly, "
        "snarls @S@'Nay! Nay, I will not go back!' @D@She raises her arm "
        "behind her head, a rock in her hand. She pauses in confusion, "
        "@S@'Wait. You are not my tormentors. Who are you?'");

    addResponse("first conversation", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. You need not "
        "fear me. What is going on here?");

    addResponse("first conversation", "I am an agent of the king...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'I am here by the authority of "
        "King Ardenel of Eledhel, my lady. How may I be of service?'");

    addResponse("first conversation", "No, who are you?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'Nay my lady, who are you and what "
        "has happened here?");

    addTopic("gave name", "@D@She smiles warmly and says, @S@'Well met, "
        "##ActorName##. I am Maiwyn. As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addTopicEvent("gave name", "playerGaveName");
    addTopicEvent("gave name", "revealName");
    addResponseTopic("first conversation", "I am...", "gave name");
    addResponse("gave name", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("gave title", "@D@She smirks slightly and says, @S@'Well, you're "
        "certainly dressed the part. I am Maiwyn. I must have been "
        "captured a very long time indeed, for the Aegis Guard I "
        "remember would not think so little of their mission and the kingdom "
        "they serve so as to hide their identity. No matter. I shan't pry. "
        "As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addTopicEvent("gave title", "revealName");
    addResponseTopic("first conversation", "I am an agent of the king...", 
        "gave title");
    addResponse("gave title", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. Apologies, "
        "but discretion seemed the wisest course.'");
    addResponse("gave title", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("was rude", "@D@She smirks and dryly replies, @S@'Say not that "
        "chivalry is dead in the Aegis Guard. Aye, I know what you are "
        "and that is enough for my request. I am Maiwyn and as for what "
        "has happened here...'"
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addTopicEvent("was rude", "revealName");
    addResponseTopic("first conversation", "No, who are you?",
        "was rude");
    addResponse("was rude", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. Apologies, "
        "but discretion seemed the wisest course.'");
    addResponse("was rude", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("gave name second chance", "@D@She smiles warmly and says, "
        "@S@'Well met, ##ActorName##. There is wisdom in caution... I "
        "am honored that you have chosen to trust me with your name.");
    addResponseTopic("gave title", "I am...", "gave name second chance");
    addResponseTopic("was rude", "I am...", "gave name second chance");
    addTopicEvent("gave name second chance", "playerGaveName");
    addResponse("gave name second chance", "@I@Continue@E@", "@I@Continue@E@");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynStoryPartOne()
{
    addTopic("story part one", "@S@'I was waylaid on my way from Eledhel to "
        "my family's estate in Ethyl Tirath...' @D@Maiwyn appears to be "
        "doing some mental gymnastics and then asks, @S@'What year is it?'");
    addResponseTopic("gave name second chance", "@I@Continue@E@", 
        "story part one");
    addResponseTopic("gave name", "@I@Continue@E@", "story part one");
    addResponseTopic("gave title", "@I@Continue@E@", "story part one");
    addResponseTopic("was rude", "@I@Continue@E@", "story part one");

    addResponse("story part one", "It is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'It is "
        "##CallOther::getDateAndTime##.'");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynStoryPartTwo()
{
    addTopic("story part two", "@S@'You cannot be serious! I have been "
        "here for eight years then. They have stolen so much of my life..."
        "' @D@Maiwyn trails off, deep in contemplation. @S@'I and a dozen "
        "others have been held here... over the years, many others have been "
        "killed, many... abused. The periods of simple neglect are the "
        "best. I would say a good score or so of these outlaws are in "
        "this ruin at any given time, though many more are constantly "
        "coming and going.'");
    addTopic("story more info", "@S@'What else would you like to know?' "
        "@D@asks Maiwyn.");

    addResponseTopic("story part one", "It is...", "story part two");

    addResponse("story part two", "Your escape...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::look## at Maiwyn and "
        "##ResponseInfinitive::ask##, @S@'How did you escape your captors?'");
    addResponse("story more info", "Your escape...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::look## at Maiwyn and "
        "##ResponseInfinitive::ask##, @S@'How did you escape your captors?'");

    addResponse("story part two", "About these outlaws...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@'What can you tell me about these "
        "outlaws? What are they doing here?'");
    addResponse("story more info", "About these outlaws...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@'What can you tell me about these "
        "outlaws? What are they doing here?'");

    addResponse("story part two", "This ruin...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'I know that this ruin was once a "
        "fastness of the Scions of Dhuras. What can you tell me of its more "
        "recent uses?'");
    addResponse("story more info", "This ruin...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'I know that this ruin was once a "
        "fastness of the Scions of Dhuras. What can you tell me of its more "
        "recent uses?'");

    addResponse("story part two", "The other captives...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::inquire##, @S@'You "
        "mentioned other captives. What can you tell me of them?'");
    addResponse("story more info", "The other captives...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::inquire##, @S@'You "
        "mentioned other captives. What can you tell me of them?'");

    addResponse("story more info", "What did they do to you?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'What "
        "have you done here these last eight years? What did they do to "
        "you?'");
    addResponsePrerequisite("story more info", "What did they do to you?", ([
        "spoken topic":([
            "type": "spoken topics",
            "value": ({ "the outlaws" })
        ])
    ]));

    addResponse("story more info", "Assistance @I@Quest@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'The crimes committed here cannot "
        "go unanswered. You know the lay of this place. Given what you said "
        "about this Lord Sullath, things here are quite obviously more "
        "far-reaching than just a pack of brigands preying on the land here. "
        "It would be in Eledhel's best interests for this to be stopped. I "
        "believe you would be a great asset toward reaching that goal. What "
        "say you?'");
    addResponsePrerequisite("story more info", "Assistance @I@Quest@E@", ([
        "spoken topic":([
            "type": "spoken topics",
            "value": ({ "my escape", "the outlaws", "this ruin",
                "other captives" })
        ])
    ]));
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionEscape()
{
    addTopic("my escape", "@S@'It was one of the outlaw's...' @D@Maiwyn's "
        "face flashes a hint of pain that is quickly sealed behind a wall. "
        "She continues levelly, @S@'time to be with me. He threw me down "
        "and I was fortunate enough to find this rock. After I killed him, "
        "I fled the scene and met up with you as I was about to leave "
        "this place. I know that it looks like I am running to save only "
        "myself, but please believe me - I was going to report this as "
        "soon as I got to safety. You being here opened up another "
        "possibility.'");
    addResponseTopic("story part two", "Your escape...", "my escape");
    addResponseTopic("story more info", "Your escape...", "my escape");
    addResponse("my escape", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("my escape", "@I@Continue@E@", "story more info");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionOutlaws()
{
    addTopic("the outlaws", "@S@'They are brutal and efficient. The man in "
        "charge here is called \"Vargath\". He is just a thuggish crony of "
        "a man known as \"Lord Sullath\". In all the time I have "
        "been here, I've seen him but a couple times. He does not pay "
        "any attention to us prisoners, but he exudes a darkness about "
        "himself.' @D@Maiwyn shudders at this and then continues. @S@'"
        "When I first met him, he stated that he has set himself to "
        "seize control of Eledhel. He practically swooned as he mentioned "
        "his devoted worship of his mistress - one he calls Seilyndria...");

    addTopicInterjection("the outlaws",
        "/areas/tol-dhurath/characters/galadhel/galadhel.c",
        "seilyndria", 1);
    addResponseTopic("story part two", "About these outlaws...", "the outlaws");
    addResponseTopic("story more info", "About these outlaws...", "the outlaws");

    addResponse("the outlaws", "Did you say Seilyndria? @A@Theology@E@",
        "@S@'Did you say Seilyndria? As in the Goddess of Destruction?' "
        "@C@##InitiatorName## ##ResponseInfinitive::trail## off, "
        "seemingly deep in thought.");
    addResponsePrerequisite("the outlaws",
        "Did you say Seilyndria? @A@Theology@E@",
        (["theology":(["type":"skill", "value" : 1])]), 1);

    addResponse("the outlaws", "Galadhel?",
        "@S@'You are familiar with this Seilyndria, Galadhel?' @D@"
        "@C@##InitiatorName## ##ResponseInfinitive::ask## in a troubled "
        "voice.");
    addResponsePrerequisite("the outlaws", "Galadhel?",
        (["presence":(["type":"presence", "value" : ({ "galadhel" })])]));

    addResponse("the outlaws", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("outlaws - seilyndria", "@D@Maiwyn's face is very difficult "
        "to read. She bites down on her lip before interjecting, @S@'"
        "Lord Sullath told me a tale, about why he has taken this place "
        "for his own. It was built by the Scions of Dhuras on the site "
        "where Queen Bryleth the Vain of Andurath was defeated and "
        "captured.' @D@Maiwyn looks a little skeptical as she continues, "
        "@S@'Lord Sullath claims that Bryleth was actually Seilyndria "
        "and he chose this place to honor her as he carries out his "
        "work. He gave us two options: go through the Trial of Obedience "
        "and join his cause or serve his cause in death.'");
    addResponseTopic("the outlaws", "Did you say Seilyndria? @A@Theology@E@", 
        "outlaws - seilyndria");
    addResponseTopic("the outlaws", "Galadhel?",
        "outlaws - seilyndria");

    addResponse("outlaws - seilyndria", "And yet you live...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::state##, @S@'And here you are. "
        "Alive...'");
    addResponse("outlaws - seilyndria", "Did you join him?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::say##, @S@'How do you come to be "
        "here? I want to believe that you didn't join him, but you are "
        "here, very much alive.'");
    addResponse("outlaws - seilyndria", "His cause...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::ask##, @S@'You said he wishes to "
        "seize control of Eledhel. Do you know how?'");

    addTopic("maiwyn offended", "@D@Maiwyn erupts into tears. She "
        "angrily wipes them away and snarls, @S@'How dare you!? I only "
        "wish that these bastards had killed me! Those wretched monsters "
        "kill all the men they capture. The women, they find other uses "
        "for!' @D@She glares at ##InitiatorName## most unfriendily and "
        "suggests that ##InitiatorSubjective## do something that "
        "##InitiatorSubjective## ##ResponseInfinitive::be## anatomically "
        "ill-equipped to do.");
    addResponseTopic("outlaws - seilyndria", "And yet you live...",
        "maiwyn offended");
    addResponseTopic("outlaws - seilyndria", "Did you join him?",
        "maiwyn offended");

    addTopicInterjection("maiwyn offended",
        "/areas/tol-dhurath/characters/galadhel/galadhel.c",
        "maiwyn offended", 1);
    addResponse("maiwyn offended", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("seizing eledhel", "@D@Maiwyn sighs and forces herself to "
        "move forward with her conversation. @S@'I know only that they "
        "are raising an army. I do not know where, how many, how "
        "organized, how anything! I am simply their plaything and not "
        "considered human enough to discuss such things with.'");
    addResponseTopic("maiwyn offended", "@I@Continue@E@",
        "seizing eledhel");
    addResponseTopic("outlaws - seilyndria", "His cause...",
        "seizing eledhel");
    addResponseTopic("the outlaws", "@I@Continue@E@", "seizing eledhel");

    addResponse("seizing eledhel", "@I@Continue@E@", "@I@Continue@E@");

    addResponseTopic("seizing eledhel", "@I@Continue@E@", "story more info");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionThisRuin()
{
    addTopic("this ruin", "@S@'There are four distinct sections of this keep "
        "as far as the activities of the current occupants go: the court yard, "
        "the temple, the throne room, and the old guild hall.' @D@She "
        "wrinkles her nose slightly and adds, @S@'We're only ever allowed "
        "in the throne room and the courtyard...'");
    addResponseTopic("story part two", "This ruin...", "this ruin");
    addResponseTopic("story more info", "This ruin...", "this ruin");

    addResponse("this ruin", "The court yard...", "@D@You ask, @S@'What can "
        "you tell me about the courtyard?'");
    addResponse("this ruin", "The temple...", "@D@You ask, @S@'What can "
        "you tell me about the temple?'");
    addResponse("this ruin", "The throne room...", "@D@You ask, @S@'What can "
        "you tell me about the throne room?'");
    addResponse("this ruin", "The guild hall...", "@D@You ask, @S@'What can "
        "you tell me about the old guild hall?'");
    addResponse("this ruin", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("this ruin", "@I@Continue@E@", "story more info");

    addTopic("the court yard", "@D@Maiwyn shrugs, @S@'You're in it. On rare "
        "occasions, the outlaws train here. Us prisoners are allowed out "
        "here twice a week as Vargath doesn't like his women \"pasty "
        "as a tooth\" as he puts it.' @D@She points to the north-central "
        "part of the yard and adds, @S@'That alcove has a statue in it. "
        "I don't really know how to describe it other than to say that "
        "it's of a woman who is holding out her hand. It looks like it "
        "might have once held something, but that is no longer the case.' "
        "@D@She points a bit to the east of it and adds, @S@'The corpse "
        "of the one who tried to rape me is in that corner alcove over "
        "there.'");
    addResponseTopic("this ruin", "The court yard...", "the court yard");
    addResponse("the court yard", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("the court yard", "@I@Continue@E@", "this ruin");

    addTopic("the temple", "@S@'We're not allowed in there...' @D@"
        "Maiwyn gives a playful wink and adds, @S@'But I have heard "
        "the outlaws speak at length about it. There is what sounds "
        "like a sealed door in there - a door that Lord Sullath seems "
        "to really want access to what is behind it. They're trying "
        "and failing to open it.' @D@There is an amused glint in her "
        "eyes at this. @S@'What I do know is that they have found "
        "several much revered but long lost relics of the Scions of "
        "Dhuras when they plundered and destroyed the contents of "
        "the catacombs.'");
    addTopicInterjection("the temple",
        "/areas/tol-dhurath/characters/halgaladh/halgaladh.c",
        "scions of dhuras", 1);
    addResponseTopic("this ruin", "The temple...", "the temple");
    addResponse("the temple", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("the temple", "@I@Continue@E@", "this ruin");

    addTopic("the throne room", "@S@'The throne room and the residences "
        "to the east of it are where the outlaws live.' @D@Maiwyn "
        "grimaces as she adds, @S@'It is also where all of the "
        "prisoners are kept. Right now, there were maybe half a dozen of "
        "those vermin in there, all drinking and debauching as we "
        "speak. Maybe a dozen of them went out earlier to raid along "
        "the road. The rest - including Vargath - are likely in the "
        "rooms behind or in the temple section.'");
    addResponseTopic("this ruin", "The throne room...", "the throne room");
    addResponse("the throne room", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("the throne room", "@I@Continue@E@", "this ruin");

    addTopic("the guild hall", "@S@'I wish I could tell you more about "
        "that place.' @D@She furrows her brow as she considers what "
        "to say. @S@'It's entrance is through those doors to the "
        "southwest of here. I have heard it described as a place with a "
        "huge, many-pillared library in it. There are a couple rooms "
        "that appear to have been used for training and then there is "
        "a curious room with a... I don't know, they described it as "
        "table with glowing runes on it. Next to it is a series of "
        "bricks that can be pushed into the table. When that happens, "
        "the glowing runes change. I'm sorry, I wish I could tell you "
        "more, but I've never seen it and I've only heard through "
        "what little I could eavesdrop.'");
    addResponseTopic("this ruin", "The guild hall...", "the guild hall");
    addResponse("the guild hall", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("the guild hall", "@I@Continue@E@", "this ruin");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionOtherCaptives()
{
    addTopic("other captives", "@S@'There are maybe a dozen of us right now.'"
        " @D@Maiwyn bites her lip as she thinks about them. @S@'There are "
        "nobles. There are peasants. It matters only who is unfortunate "
        "enough to be waylaid. I do not know any of them particularly well "
        "as I have found that most do not survive very long. Long ago, I "
        "found that attachment is torture on its own and the more I learn "
        "about others, the more I must forget when they outlive their "
        "usefulness. It may sound cruel, but it is the only way I know to "
        "survive.' @D@As if coming to a realization, she adds, @S@'We are "
        "kept in the eastern part of this keep, through the eastern doors "
        "in the throne room.'");
    addResponseTopic("story part two", "The other captives...", "other captives");
    addResponseTopic("story more info", "The other captives...", "other captives");
    addResponse("other captives", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("other captives", "@I@Continue@E@", "story more info");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionWhatDidTheyDo()
{
    addTopic("what they did to me", "@D@Maiwyn's face is a study in "
        "anger and exasperation. @S@'I thought I was pretty clear! What do "
        "men such as these do with women? Must I really spell it out for "
        "you?' @D@She sighs in an attempt to dispel her anger. When she "
        "continues, her face smooths into one with practically no "
        "expression. @S@'I apologize for my response... Suffice it to say "
        "that they are quite talented in their ability to torture others. "
        "When they are not doing things TO us, we are their slaves.'");
    addResponseTopic("story more info", "What did they do to you?",
        "what they did to me");
    addResponse("what they did to me", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("what they did to me", "@I@Continue@E@", "story more info");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynGoForthAndQuest()
{
    addTopic("go forth and quest", "@D@Maiwyn looks longingly at the gate "
        "house, clearly conflicted between fleeing to safety and helping. "
        "She turns to ##InitiatorName## and finally says, @S@'Very well. I "
        "will do what I can, but I warn you: I am no fighter. If you are "
        "asking that of me, I fear you will be deeply disappointed. When "
        "blows land, I will be doing my best to get out of the way.' "
        "@D@Maiwyn points to the south and adds, @S@'You might start by "
        "barring the gate. No sense in having the others interrupt us with "
        "their return.'");
    addResponseTopic("story more info", "Assistance @I@Quest@E@",
        "go forth and quest");
    addResponseEffect("story more info", "Assistance @I@Quest@E@",
        (["join":1])); 
    addTopicEvent("go forth and quest", "maiwyn helps");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    MaiwynIntroduced();
    MaiwynStoryPartOne();
    MaiwynStoryPartTwo();
    MaiwynDiscussionEscape();
    MaiwynDiscussionOutlaws(); 
    MaiwynDiscussionThisRuin();
    MaiwynDiscussionOtherCaptives();
    MaiwynDiscussionWhatDidTheyDo();
    MaiwynGoForthAndQuest();
}
