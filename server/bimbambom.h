#ifndef BIMBAMBOM_H_
#define BIMBAMBOM_H_

struct Song {
  int bpm;
  int notes;
};

void bimbambom(struct Song *song);

#endif // BIMBAMBOM_H_