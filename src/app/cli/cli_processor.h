// Aseprite
// Copyright (C) 2016-2018  David Capello
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_APP_CLI_PROCESSOR_H_INCLUDED
#define APP_APP_CLI_PROCESSOR_H_INCLUDED
#pragma once

#include "app/cli/cli_delegate.h"
#include "app/cli/cli_open_file.h"
#include "base/unique_ptr.h"

#include <string>
#include <vector>

namespace app {

  class AppOptions;
  class Context;
  class DocumentExporter;

  class CliProcessor {
  public:
    CliProcessor(CliDelegate* delegate,
                 const AppOptions& options);
    void process(Context* ctx);

  private:
    bool openFile(Context* ctx, CliOpenFile& cof);
    void saveFile(Context* ctx, const CliOpenFile& cof);

    CliDelegate* m_delegate;
    const AppOptions& m_options;
    base::UniquePtr<DocumentExporter> m_exporter;
  };

} // namespace app

#endif
