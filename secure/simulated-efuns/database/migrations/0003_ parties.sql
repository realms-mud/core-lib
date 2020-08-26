CREATE TABLE `parties` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `creatorid` int(11) NOT NULL,
  `partyName` varchar(256) NOT NULL,
  KEY `parties_id_idx` (`id`),
  CONSTRAINT `parties_creatorid` FOREIGN KEY (`creatorid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `partyMembers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `partyid` int(11) NOT NULL,
  `member` varchar(256) NOT NULL,
  `memberType` varchar(12) NOT NULL,
  `experienceEarned` int(11) NOT NULL,
  `bestKill` varchar(256) NOT NULL,
  `memberFollowing` varchar(256),
  KEY `partyMembers_id_idx` (`id`),
  CONSTRAINT `partyMembers_partyid` FOREIGN KEY (`partyid`) REFERENCES `parties` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
