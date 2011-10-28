BANDWIDTH_TEST: try loading textures as fast as possible, without using them. Used as reference for max bandwidth available in video card
SINGLE_NOSYNC_NOPBO
SINGLE_NOSYNC_PBO
MULTI_SYNC_NOPBO
MULTI_SYNC_PBO
MULTI_NOSYNC_NOPBO
MULTI_NOSYNC_PBO

pbo/nopbo: use pbo or direct loading from conventional memory buffer
single/multi: single (one for each main loop) or dual thread loading of textures.
sync/nosync: use vsync and limit framerate to screen refresh ratio. nosync + thread has a Sleep(5) at the end of drawing to allow some cpu time to secondary thread.