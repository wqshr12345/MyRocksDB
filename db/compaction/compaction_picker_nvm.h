#pragma once
#ifndef ROCKSDB_LITE

#include "db/compaction/compaction_picker.h"

namespace ROCKSDB_NAMESPACE {
    //为我们的项目进行compaction的选择
class NvmCompactionPicker : public CompactionPicker {
 public:
  NvmCompactionPicker(const ImmutableOptions& ioptions,
                            const InternalKeyComparator* icmp)
      : CompactionPicker(ioptions, icmp) {}
  virtual Compaction* PickCompaction(
      const std::string& cf_name, const MutableCFOptions& mutable_cf_options,
      const MutableDBOptions& mutable_db_options, VersionStorageInfo* vstorage,
      LogBuffer* log_buffer,
      SequenceNumber earliest_memtable_seqno = kMaxSequenceNumber) override;
  virtual int MaxOutputLevel() const override { return NumberLevels() - 1; }

  virtual bool NeedsCompaction(
      const VersionStorageInfo* vstorage) const override;
};
}  // namespace ROCKSDB_NAMESPACE
#endif  // !ROCKSDB_LITE
